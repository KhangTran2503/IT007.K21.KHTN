#!/bin/sh

echo "Enter your name"
read Name

echo "Enter your ID"
read mssv

while [ "$mssv" != "18520072" ]; do
	echo "This is not $Name's ID"
	echo "Please, try enter your ID again!!!"
	read mssv
done 

echo "Wellcome!!!"
exit 0
