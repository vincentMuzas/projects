#!/bin/sh

VAR=$(cat);

echo "$VAR" | sed -n '1~2p'
