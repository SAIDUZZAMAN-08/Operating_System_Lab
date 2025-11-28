#!/bin/bash
read -p "Enter filename: " file

if c then
    echo "$file is a regular file."
elif [ -d "$file" ]; then
    echo "$file is a directory."
else
    echo "$file does not exist."
fi
