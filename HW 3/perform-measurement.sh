#!/usr/bin/bash
# Arnav Mathur
# CSE 374 22sp HW 3
# Part 1
# 4/20/2022

if [ $# -lt 1 ]; then
   echo "Error: no arguments passed" >&2
   exit 1
fi

# Creates a temp file and redirects stderr to dev/null.
URL="$1"
OUTPUT=`mktemp -p '/tmp' -t 'tempXXX' 2> /dev/null`

# Downloads the file from the web and links it with URL.
# Only tries 1 time to find the webpage, allows for 2 seconds of searching then times out if page doesn't exist
wget -t 1 -T 2 -o /dev/null -O "$OUTPUT" "$URL" || { echo "0"; rm "$OUTPUT" 2> /dev/null; exit 2;}

# Finds the word count of the file and outputs it into the terminal
wc -c < "$OUTPUT" || { echo "0"; rm "$OUTPUT" 2> /dev/null; exit 3;}
rm "$OUTPUT" 2> /dev/null

exit 0