#!/bin/bash

# Using the df command to get storage usage information
df_output=$(df -h)

# Display storage usage and available storage for each partition
echo "Storage usage on partitions:"
echo "$df_output"

# Split the df output into lines
lines=($(echo "$df_output" | tr '\n' ' '))

# Get used and available storage on the root partition (/)
used=$(echo "${lines[11]}" | tr -d ' ')
available=$(echo "${lines[15]}" | tr -d ' ')

echo "Storage usage on the root partition (/): $used"
echo "Available storage on the root partition (/): $available"