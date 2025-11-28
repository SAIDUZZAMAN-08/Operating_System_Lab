#!/bin/bash

read name

read -p "Enter the first numbe: " a
read -p "Enter the second number: " b

echo "Your name is: $name"
echo "Sum is $((a+b))"
echo "Product is $((a*b))"

