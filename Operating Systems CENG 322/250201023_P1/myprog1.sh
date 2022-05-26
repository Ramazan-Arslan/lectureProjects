#!/bin/bash
# Ramazan Arslan - 250201023
fileName=$1
n=0
while read line; # reading each line
do
    printf '%1.s*' $(seq 1 $line)
    echo ""
    n=$((n+1))
done < $fileName


