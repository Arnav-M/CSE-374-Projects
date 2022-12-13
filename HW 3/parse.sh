#!/usr/bin/bash
# Arnav Mathur
# CSE 374 22sp HW 3
# Part 2
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

# Filters HTML document for webpage links.
grep -Eo '<strong><a [^>]+>' "$INPUT" | grep -Eo 'http://[^/"]+' > "$OUTPUT"

exit 0