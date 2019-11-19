#!/bin/sh
if [ $# -eq 0 ]
then
	echo "0";
	return 0;
fi

FILE=$(cat);
echo "$FILE" | cut -d \; -f 3 | grep -i $1 | wc -l