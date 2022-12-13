#!/usr/bin/bash
# Arnav Mathur
# CSE 374 22sp HW 3
# Part 3
# 4/20/2022

if [ $# -lt 2 ]; then
    echo "Error 404: this function requires two arguments to be passed" >&2
    exit 1
fi 

if [ ! -e "$1" ]; then
    echo "HTML file '$1' does not exist. Try again." >&2
    exit 1
fi

INPUT="$1"
OUTPUT="$2"
RANK=0

# Find the size of all URLs present in the HTML file and outputs their RANK URL and SIZE in one
# line. If a website is not accessible then a fail message is passed otherwise a success message 
# pops up.
while IFS='' read -r URL; do
    echo "Performing measurement on $URL"
    let RANK=RANK+1
    SIZE=`./perform-measurement.sh "$URL"`
    if [ $SIZE -gt 0 ]; then
        echo "...success" 
        echo "$RANK $URL $SIZE" >> "$OUTPUT"
    else 
        echo "...failed"
    fi
done < "$INPUT"
exit 0