const router = require("express").Router();
const { User, validate } = require("../models/user");
const Token = require("../models/token");
const crypto = require("crypto");
const sendEmail = require("../utils/sendEmail");
const bcrypt = require("bcrypt");

// Route to create a new user
router.post("/", async (req, res) => {
  try {
    // Validate the request body
    const { error } = validate(req.body);
    if (error)
      return res.status(400).send({ message: error.details[0].message });

    // Check if a user with the same email already exists
    let user = await User.findOne({ email: req.body.email });
    if (user)
      return res
        .status(409)
        .send({ message: "User with the given email already exists!" });

    // Generate a salt and hash the password
    const salt = await bcrypt.genSalt(Number(process.env.SALT));
    const hashPassword = await bcrypt.hash(req.body.password, salt);

    // Create a new user with the hashed password
    user = await new User({ ...req.body, password: hashPassword }).save();

    // Generate a verification token
    const token = await new Token({
      userId: user._id,
      token: crypto.randomBytes(32).toString("hex"),
    }).save();
    
    // Create a verification URL and send an email
    const url = `${process.env.BASE_URL}users/${user.id}/verify/${token.token}`;
    await sendEmail(user.email, "Verify Email", url);

    res
      .status(201)
      .send({ message: "An email has been sent to your account; please verify it." });
  } catch (error) {
    console.error(error);
    res.status(500).send({ message: "Internal Server Error" });
  }
});

// Route to verify an email
router.get("/:id/verify/:token", async (req, res) => {
  try {
    // Find the user by ID
    const user = await User.findOne({ _id: req.params.id });
    if (!user) return res.status(400).send({ message: "Invalid link" });

    // Find the verification token
    const token = await Token.findOne({
      userId: user._id,
      token: req.params.token,
    });
    if (!token) return res.status(400).send({ message: "Invalid link" });

    // Update the user's verification status
    await User.updateOne({ _id: user._id }, { verified: true });
	await token.remove();
    res.status(200).send({ message: "Email verified successfully" });
  } catch (error) {
    console.error(error);
    res.status(500).send({ message: "Internal Server Error" });
  }
});

module.exports = router;
