#!/bin/sh
git add --all
if [ $# -eq 0 ]
then
	git commit -m "commit"
else
	git commit -m $1;
fi
git push origin master