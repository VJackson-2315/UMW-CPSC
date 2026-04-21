#!bin/bash

filename='abuse-emails.txt'
if [ ! -e $filename ]
then
	touch $filename
fi


addresses=`grep 'Invalid user' /var/log/auth.log | awk '{print $8;}' | sort | uniq`
for i in $addresses
do
	echo $i, `whois $i | grep -i 'abuse-mailbox' | awk '{print $2}' | uniq` >> $filename
	
done
