#!/bin/sh

echo "Enter pattern"
read pattern

flat=0
for file in $(ls *.txt)
do
	if grep -i -l "$pattern" $file
	then 
		flat=1
	fi
done 

if [ "$flat" = "0" ]
then 
	echo "Can not find file!"
fi

exit 0
