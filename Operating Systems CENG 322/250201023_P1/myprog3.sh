#!/bin/bash
# Ramazan Arslan - 250201023
DIRECTORY=$1  # gets input from location 1 ./test.sh INPUT

if [[ -z "$DIRECTORY" ]]; then # checks directory path is empty
    DIRECTORY=*  # current location
else
    [ ! -d "$DIRECTORY" ] && exit 1;  # if given directory is not a directory
    cd $DIRECTORY # goes the input
fi

current=$(pwd) # gets current directroy for come back


for f in *; do # for files in given directory

    if [[ -f $f ]]; then #if it is a file
        fsize=$(wc -c "$f" | awk '{print $1}') # gets file size with wc
        if [[ "$fsize" == 0 ]]; then # if file size is 0 
            rm $f # deletes files
            echo "$f removed from the directory"
        fi
    fi
done


cd $current # comes back to home directory