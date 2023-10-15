#!/bin/bash

# Check if the 'top' command is available
if ! [ -x "$(command -v top)" ]; then
  echo "The 'top' command is not installed. Please install it."
  exit 1
fi

# Continuously monitor system resource usage
while true
do
  clear  # Clear the terminal screen
  echo "System Resource Monitoring (Press 'q' to quit)"
  echo "---------------------------------------------"
  top -b -n 1  # Display resource usage once
  sleep 1  # Wait for 1 second before updating again
done
