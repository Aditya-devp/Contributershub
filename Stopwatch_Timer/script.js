let isRunning = false;
let stopwatchInterval;
let milliseconds = 0;
let clockColorChangeInterval;

document.getElementById("stopwatch").addEventListener("click", toggleStopwatch);

function toggleStopwatch() {
    if (!isRunning) {
        document.querySelector(".datetime p").textContent = "";
        startStopwatch();
        startClockColorChange();
    } else {
        document.querySelector(".datetime p").textContent = "Click to Start";
        stopStopwatch();
        clearInterval(clockColorChangeInterval);
        resetClockStyle();
    }
}

function startClockColorChange() {
    clockColorChangeInterval = setInterval(toggleClockStyle, 1000);
}

function toggleClockStyle() {
    const datetime = document.querySelector(".datetime");
    datetime.classList.toggle("clock-color-glow");
}

function resetClockStyle() {
    const datetime = document.querySelector(".datetime");
    datetime.classList.remove("clock-color-glow");
}

function startStopwatch() {
    stopwatchInterval = setInterval(function () {
        milliseconds += 10;
        if (milliseconds === 1000) {
            milliseconds = 0;
            incrementTime();
        }
        updateDisplay();
    }, 10);
    isRunning = true;
}

function stopStopwatch() {
    clearInterval(stopwatchInterval);
    isRunning = false;
}

function incrementTime() {
    let seconds = parseInt(document.getElementById("seconds").textContent, 10);
    let minutes = parseInt(document.getElementById("minutes").textContent, 10);
    let hours = parseInt(document.getElementById("hour").textContent, 10);

    seconds++;

    if (seconds === 60) {
        seconds = 0;
        minutes++;
    }

    if (minutes === 60) {
        minutes = 0;
        hours++;
    }

    document.getElementById("hour").textContent = hours.toString().padStart(2, "0");
    document.getElementById("minutes").textContent = minutes.toString().padStart(2, "0");
    document.getElementById("seconds").textContent = seconds.toString().padStart(2, "0");
}

function updateDisplay() {
    document.getElementById("milliseconds").textContent = milliseconds.toString().padStart(3, "0");
}
