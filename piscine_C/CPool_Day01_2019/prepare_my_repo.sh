#!/bin/sh
if [ $# -eq 0 ]
	then
		return 84
fi

blih -u vincent.muzas@epitech.eu repository create $1
blih -u vincent.muzas@epitech.eu repository setacl $1 ramassage-tek r
blih -u vincent.muzas@epitech.eu repository getacl $1
return 0