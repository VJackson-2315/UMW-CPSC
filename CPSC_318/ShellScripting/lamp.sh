#!/bin/bash

# Had to retype all of this in the og virtual machine since fileZilla wasn't working with it :(

read -s -p "Enter your password: " password
echo -e "\n"

sudo apt install mariadb-server mariadb-client
echo -e "\nN\nY\n$password\n$password\nY\nY\nY\nY" | sudo mysql_secure_installation
sudo apt install php libapache2-mod-php php-cli php-fpm php-json php-pdo php-mysql php-zip php-gd php-mbstring php-curl php-xml php-pear php-bcmath
sudo a2enmod "php8.2"

mysql -u root -p"$password" -e "DROP DATABASE IF EXISTS wp_database;"
mysql -u root -p"$password" -e "DROP USER IF EXISTS 'wpuser'@'localhost';"
mysql -u root -p"$password" -e "CREATE DATABASE wp_database;"
mysql -u root -p"$password" -e "CREATE USER 'wpuser'@'localhost' IDENTIFIED BY '$password';"
mysql -u root -p"$password" -e "GRANT ALL ON \`wp_database\`.* TO \`wpuser\`@\`localhost\`;"
mysql -u root -p"$password" -e "FLUSH PRIVILEGES;"

wget https://wordpress.org/latest.tar.gz
tar -xzf latest.tar.gz
dir="/var/www/html/"
if [ `ls $dir | wc -l` -ne 0 ]
then
	echo "Removing files from $dir ..."
	sudo rm -rf "$dir"*
fi
echo "Moving all files to $dir ..."
sudo mv wordpress/* $dir
rm -r wordpress latest.tar.gz
sudo chown www-data "$dir"*

sudo cp "$dir"wp-config-sample.php "$dir"wp-config.php

sudo sed -i "s/database_name_here/wp_database/" "$dir"wp-config.php
sudo sed -i "s/username_here/wpuser" "$dir"wp-config.php
sudo sed -i "s/password_here/$password/" "$dir"wp-config.php

echo -e "\nYou're almost done! Put the external IP address in your browser to finish."
