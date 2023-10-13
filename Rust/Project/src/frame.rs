// Importing the constants `NUM_COLS` and `NUM_ROWS` from the crate.
use crate::{NUM_COLS, NUM_ROWS};

// Defining a type alias `Frame` as a vector of vectors of string references.
pub type Frame = Vec<Vec<&'static str>>;

// A function to create a new frame, initializing it with empty spaces.
pub fn new_frame() -> Frame {
    let mut cols = Vec::with_capacity(NUM_COLS);
    for _ in 0..NUM_COLS {
        let mut col = Vec::with_capacity(NUM_ROWS);
        for _ in 0..NUM_ROWS {
            col.push(" ");
        }
        cols.push(col);
    }
    cols
}

// A trait `Drawable` that defines a method to draw an object onto a frame.
pub trait Drawable {
    // Method to draw the object onto the provided frame.
    fn dra(&self, frame: &mut Frame);
}
