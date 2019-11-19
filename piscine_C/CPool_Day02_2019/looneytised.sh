#!/bin/sh

FILE=$(cat);
echo "$FILE" | grep -E 'theo1|steven1|arnaud1|pierre-jean' | sed 's/theo1/Wile E. Coyote/g' | sed 's/steven1/Daffy Duck/g' | sed 's/arnaud1/Porky Pig/g' | sed 's/pierre-jean/Marvin the Martian/g'