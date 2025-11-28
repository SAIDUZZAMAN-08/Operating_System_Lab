#!/bin/bash
while true
do
    echo "1. Show Date"
    echo "2. Show Calendar"
    echo "3. Show Username"
    echo "4. Exit"
    read -p "Enter choice: " ch

    case $ch in
        1) date ;;
        2) cal ;;
        3) whoami ;;
        4) break ;;
        *) echo "Invalid option!" ;;
    esac
done
