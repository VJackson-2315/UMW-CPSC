#!bin/bash

filename='ssh-attempts.txt'
if [ ! -e filename ]
then
	touch $filename
fi

# Did have to look up how to cut out "user=" from the output

egrep -o '\<user=.*' /var/log/auth.log | cut -c 6- | sort -r | uniq >> $filenamg
