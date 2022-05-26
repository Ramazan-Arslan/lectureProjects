#!/bin/bash
# Ramazan Arslan - 250201023
echo 'Enter a sequence of number followed by "end"'
while read line # takes inputs from the user
do
    if [ $line == "end" ]; #end condition
    then 
        break
    else
        numbers=("${numbers[@]}" $line) # add numbers to numbers array
    fi
done

maxNumber=numbers[0] #max number equals to first input
for v in ${numbers[@]}; 
do
    if (( $v > $maxNumber ));  # if number greater then previous maxNumber, new maxNumber will update.
    then maxNumber=$v; 
    fi; 
done
echo "Maximum : $maxNumber"
