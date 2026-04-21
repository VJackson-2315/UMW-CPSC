#!bin/bash

filename='country-access.txt'
if [ ! -e filename ]
then
	touch $filename
fi

awk '{print $1;}' /var/log/apache2/access.log | uniq | xargs -l whois | awk '/country/{print $2}' | sort | uniq > $filename

echo "Logged into $filename"
