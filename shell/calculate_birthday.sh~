#! /bin/bash

PATH=$PATH
export PATH

echo "This program will try to calculate:"
echo "How many days before you birthday..."
read -p "Please input you birthday date (MMDD ex>1029):" date2
year2=$((`date +%Y`)) # 当年的生日
date2="$year2""$date2"
echo $date2
date_d=$(echo "$date2" | grep '[0-9]\{8\}')
if [ "$date_d" == "" ]; then
    echo "You input the wrong date...."
    exit 1
fi
declare -i date_i=`date --date="$date_d" +%s`
declare -i date_now=`date +%s`
declare -i date_total_s=$(($date_i-$date_now))
declare -i date_total_d=$(($date_total_s/60/60/24))
if [ "$date_total_d" -lt "0" ];then
    echo "Your birthday has already passed "$((-1*$date_total_d))" ago"
else
    declare -i date_h=$(($(($date_total_s-$date_total_d*24*60*60))/60/60))
    echo "Your birthday will come in $date_total_d days and $date_h hours" 
fi

