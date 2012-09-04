#! /bin/bash

PATH=$PATH
export PATH
function printit(){
    echo -n "Hello"
}
declare -i val_i="0"

while [ $((val_i<10)) == "1" ]
do
    printit
    $val_i=$((val_i++))
done