use std::time::Duration;

use rusty_time::timer::Timer;

use crate::frame::{Drawable, Frame};

// Structure to represent a shot fired by the player's spaceship.
pub struct Shot {
    pub x: usize,
    pub y: usize,
    pub exploding: bool,
    timer: Timer,
}
impl Shot {
    // Structure to represent a shot fired by the player's spaceship.
    pub fn new(x: usize, y: usize) -> Self {
        Self {
            x,
            y,
            exploding: false,
            timer: Timer::from_millis(50),
        }
    }
    // Update method to move the shot upwards and handle explosion

    pub fn update(&mut self, delta: Duration) {
        self.timer.update(delta);
        if self.timer.ready && !self.exploding {
            if self.y > 0 {
                self.y -= 1;
            }
            self.timer.reset();
        }
    }

    // Trigger the explosion of the shot
    pub fn explode(&mut self) {
        self.exploding = true;
        self.timer = Timer::from_millis(250);
    }

    // Check if the shot is dead (exploded or out of frame).
    pub fn dead(&self) -> bool {
        (self.exploding && self.timer.ready) || (self.y == 0)
    }
}

//Implementing the Drawable trait for Shot.
impl Drawable for Shot {
    fn dra(&self, frame: &mut Frame) {
        frame[self.x][self.y] = if self.exploding { "*" } else { "|" };
    }
}
