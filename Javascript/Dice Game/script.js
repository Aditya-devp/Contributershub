'use strict';
// Selecting elements
const player0El = document.querySelector('.player--0');
const player1El = document.querySelector('.player--1');
const score0El = document.querySelector('#score--0');
const score1El = document.getElementById('score--1'); // for selcting Id
const current0El = document.getElementById('current--0');
const current1El = document.getElementById('current--1');

const diceEl = document.querySelector('.dice');
const btnNew = document.querySelector('.btn--new');
const btnroll = document.querySelector('.btn--roll');
const btnHold = document.querySelector('.btn--hold');

let playing = true; // if game is playing
let scores = [0, 0]; // final scores total
let currentScore = 0; // for updating it
let activePlayer = 0; // player 1 is 0 suppose

const init = function () {
  playing = true; // if game is playing
  scores = [0, 0]; // final scores total
  currentScore = 0; // for updating it
  activePlayer = 0; // player 1 is 0 suppose
  playing = true;

  score0El.textContent = 0;
  score1El.textContent = 0;
  current0El.textContent = 0;
  current1El.textContent = 0;

  diceEl.classList.add('hidden');
  player0El.classList.remove('player--winner');
  player1El.classList.remove('player--winner');
  player0El.classList.add('player--active');
  player1El.classList.remove('player--active');
};
init();
// Switch player function
const switchPlayer = function () {
  document.getElementById(`current--${activePlayer}`).textContent = 0;
  //Switch to next player turn by changing value of active player
  // reassigning the value
  currentScore = 0;
  activePlayer = activePlayer == 0 ? 1 : 0;

  // toggle will add if not present and if present then remove

  player0El.classList.toggle('player--active');
  player1El.classList.toggle('player--active');
};

// Rolling Dice Functionality

// event name click
btnroll.addEventListener('click', function () {
  //1- Generating a random dice roll
  if (playing) {
    const dice = Math.trunc(Math.random() * 6) + 1;

    // for playing
    // 2- Display Dice
    diceEl.classList.remove('hidden');
    diceEl.src = `dice-${dice}.png`; // just like html
    console.log(dice);

    // 3-Check for rolled 1: if true switch to next player
    if (dice !== 1) {
      // scores[activePlayer] += currentScore;
      // console.log(scores[activePlayer]);
      document.getElementById(`score--${activePlayer}`).textContent = dice;

      // current0El.textContent=currentScore;  // change Later

      // Add dice to current score
      currentScore += dice;
      // dynamically checking

      document.getElementById(`current--${activePlayer}`).textContent =
        currentScore;
    } else {
      // for 1
      // Before  switching make current score =0
      // document.getElementById(`current--${activePlayer}`).textContent=0;
      // //Switch to next player turn by changing value of active player
      // // reassigning the value
      // currentScore=0;
      // activePlayer= activePlayer==0 ? 1:0;

      // // toggle will add if not present and if present then remove

      // player0El.classList.toggle('player--active');
      // player1El.classList.toggle('player--active');

      switchPlayer();
    }
  }
});
btnHold.addEventListener('click', function () {
  // 1) Add Current score to the score active player
  if (playing) {
    scores[activePlayer] += currentScore;
    // score[1]=scores[1]+currentScore
    document.getElementById(`score--${activePlayer}`).textContent =
      scores[activePlayer];
    // 2) chack if score >=100

    if (scores[activePlayer] >= 20) {
      // Finish the game
      playing = false;
      document.getElementById(`score--${activePlayer}`).textContent =
        'Winner 😃';
      diceEl.classList.add('hidden');
      document
        .querySelector(`.player--${activePlayer}`)
        .classList.add('player--winner');
      document
        .querySelector(`.player--${activePlayer}`)
        .classList.remove('player--active');
    }
    // Switch to next player
    else {
      switchPlayer();
    }
  }
});

btnNew.addEventListener('click', init); // init value will be written
