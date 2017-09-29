#!/bin/bash

i=$(wc -c < $1)

while [ $i -le $2 ]
do
	echo -n "ha" >> $1;
	i=$(wc -c < $1);
done
