#!/bin/bash

echo "Do you agree with the following statement? "
echo -n "All squares are diamonds. [yes or no]: "
read yno
#yon="yes"
#echo $yon
case $yno in 
	[yY]|[yY][eE][sS]) echo "Correct!";;
	[nN]|[nN][oO]) echo "That is incorrect! :(";;
	*) echo "Invalid input";;
esac

