use rand::Rng;
use std::io;

fn generate_password(length: usize) -> String {
    let chars: &str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[{]}|;:',<.>/?";
    let mut rng = rand::thread_rng();
    (0..length)
        .map(|_| rng.gen_range(0..chars.len()))
        .map(|i| chars.chars().nth(i).unwrap())
        .collect()
}

fn main() {
    println!("Welcome to the Rust Password Generator!");

    println!("Enter the length of the password:");
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let length: usize = input.trim().parse().expect("Please enter a valid number");

    let password = generate_password(length);
    println!("Generated Password: {}", password);
}
