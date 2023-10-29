const messages = [
    "Learn React ⚛️",
    "Apply for jobs 💼",
    "Invest your new income 🤑"
  ];
  
  // Selecting DOM elements
  const step1 = document.querySelector(".step-1");
  const step2 = document.querySelector(".step-2");
  const step3 = document.querySelector(".step-3");
  const message = document.querySelector(".message");
  const btnPrevious = document.querySelector(".previous");
  const btnNext = document.querySelector(".next");
  
  // "State"
  let step = 1;
  
  // Manually updating the DOM: changing text content and adding/removing classes (imperative approach)
  const updateUIValues = function () {
    message.textContent = `Step ${step}: ${messages[step - 1]}`;
  
    if (step >= 1) step1.classList.add("active");
    else step1.classList.remove("active");
  
    if (step >= 2) step2.classList.add("active");
    else step2.classList.remove("active");
  
    if (step >= 3) step3.classList.add("active");
    else step3.classList.remove("active");
  };
  
  // Initial setup
  updateUIValues();
  
  // Manually attaching event listeners
  btnPrevious.addEventListener("click", function () {
    if (step > 1) step -= 1;
    updateUIValues();
  });
  
  btnNext.addEventListener("click", function () {
    if (step < 3) step += 1;
    updateUIValues();
  });
  