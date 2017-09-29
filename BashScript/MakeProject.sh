#!/bin/bash


#Go to home directory
cd /home/justin

#check if subfolder project exists, if not create it.
if [ ! -e project ];then 
	mkdir project
fi

#Move into project directory
cd project

#Verify if subdirectory cs206 exists, if not create it
if [ ! -e cs206 ]; then
	mkdir cs206
fi

#Move to cs206
cd cs206

#Check if the name provided exists:
if [ -e $1 ]; then 
	echo "This project name has already been used"
else 
	mkdir $1;mkdir $1/archive;mkdir $1/backup;mkdir $1/docs;mkdir $1/assets;mkdir $1/database;mkdir $1/source
fi

#Move into source
cd $1/source

#Generate a backup.sh script
touch backup.sh
echo "#!/bin/bash" >> backup.sh
echo "path=pwd" >> backup.sh
echo "cp *.c *.h $path+'../backup' >> backup.sh
chmod 754 backup.sh

#And we are done!
echo "You project directories have been created."

