#!/bin/bash

# Bash - Medium

# TODO: Implement the Disk Monitor script

today_date=$(date "+%y_%m_%d")
mounted_disk_devices=$(lsblk | awk '{print $7}')
disk_usage_percent=$1

for mounted_disk_devices in ${mounted_disk_devices};
do
    if [[ ${mounted_disk_devices} = '' ]]; then
        continue;
    fi ;

    if [[ ${mounted_disk_devices} = 'MOUNTPOINT' ]]; then 
        continue;
    fi;

    if [[ ${mounted_disk_devices} = 'SWAP' ]]; then
        continue;
    fi;

    disk_usage=$(df -lh ${mounted_disk_devices} | tail -n 1 | awk '{print $5}' | sed -e 's/%//g')
    if [[ ${disk_usage} -gt ${disk_usage_percent} ]]; then
        message="Disk mount point: ${mount_disk_devices} should be considred."
        echo ${message}
        echo ${message} >> "disk_usage_${today_date}.txt"
    fi;
done;