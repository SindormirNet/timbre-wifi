#!/bin/bash

while true
do 
    if nc -l 10000 -w 1 >/dev/null 
    then
        date
        play /usr/share/sounds/linphone/rings/oldphone-mono.wav 2>/dev/null
        sleep 1
        play /usr/share/sounds/linphone/rings/oldphone-mono.wav 2>/dev/null
    fi
done

exit 0
