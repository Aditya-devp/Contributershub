use std::time::Duration;

use crate::{
    frame::{Drawable, Frame},
    invaders::Invaders,
    shot::Shot,
    NUM_COLS, NUM_ROWS,
};

pub struct Player {
    x: usize,
    y: usize,
    shots: Vec<Shot>, // Vector to hold the shots fired by the player.
}

impl Player {
    // Constructor to create a new instance of Player.

    pub fn new() -> Self {
        Self {
            x: NUM_COLS / 2,
            y: NUM_ROWS - 1,
            shots: Vec::new(),
        }
    }

    // Move the player's spaceship to the left.
    pub fn move_left(&mut self) {
        if self.x > 0 {
            self.x -= 1;
        }
    }
    // Move the player's spaceship to the right.
    pub fn move_right(&mut self) {
        if self.x < NUM_COLS - 1 {
            self.x += 1;
        }
    }

    // Shoot a new shot from the player's spaceship.
    pub fn shoot(&mut self) -> bool {
        if self.shots.len() < 2 {
            self.shots.push(Shot::new(self.x, self.y - 1));
            true
        } else {
            false
        }
    }

    // Update the player's state based on elapsed time.
    pub fn update(&mut self, delta: Duration) {
        for shot in self.shots.iter_mut() {
            shot.update(delta);
        }
        self.shots.retain(|shot| !shot.dead());
    }
    // Detect hits on invaders by the player's shots and remove invaders accordingly.
    pub fn detect_hits(&mut self, invaders: &mut Invaders) -> bool {
        let mut hit_something = false;
        for shot in self.shots.iter_mut() {
            if !shot.exploding {
                if invaders.kill_invader_at(shot.x, shot.y) {
                    hit_something = true;
                    shot.explode();
                }
            }
        }
        hit_something
    }
}
// Implementing the Drawable trait for Player.
impl Drawable for Player {
    // Draw method for Player to update the frame based on the player's position and shots.
    fn dra(&self, frame: &mut Frame) {
        frame[self.x][self.y] = "A";
        for shot in self.shots.iter() {
            shot.dra(frame);
        }
    }
}
