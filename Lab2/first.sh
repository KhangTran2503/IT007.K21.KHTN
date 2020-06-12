#!bin/sh


for file in *
do
	if grep 'main()' $file
	then
		more $file
	fi
done
exit 0
