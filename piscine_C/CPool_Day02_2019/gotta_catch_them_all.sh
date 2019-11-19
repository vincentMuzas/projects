#/bin/sh

if [ $# -eq 0 ]
then
	echo "0";
	exit;
fi

FILE=$(cat);
echo "$FILE" | cut -d ":" -f 5 | cut -d " " -f 2 | grep $1 | wc -l