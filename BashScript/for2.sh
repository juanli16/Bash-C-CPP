#!/bin/bash

weekdays=" Monday Tuesday Wednesday "
i=1

for day in $weekdays
do 
	echo "Weekdays $((i++)): $day"
	#echo "$day 1"
done

