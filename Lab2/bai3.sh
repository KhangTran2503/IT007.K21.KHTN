#!/bin/sh

echo "Enter Integer n"
read n

while [ "$n" -lt 10 ]
do
	echo "Sorry, try again"
	read n
done 

Sum=0
foo=1
while [ "$foo" -le "$n" ]
do
	Sum=$(($Sum + $foo))
	foo=$(($foo + 1))
done

echo "Sum 1 to $n: $Sum"
exit 0
