# cs16v2
Codes for STCET 3rd Sem

**run.sh** – a shell script to compile and run a c code in one go without having to type 
`gcc prog.c -o prog.out`
and `./prog.out` separately


Using run.sh
-------------------

First change the permissions to make the script executable

`user@terminal:~$ chmod 744 run.sh`

*You have to do the above step just once and need to redo only if you change directory.*
*run.sh file should be present in your working directory to work*

Then simply do this to compile and run a “program.c” in one go-

`user@terminal:~$ ./run.sh program.c`

Alternate way
---------------

Set the PATH variable using export command

`mkdir ~/bin`
either go to the directory with run.sh and cp it to ~/bin

`cp run.sh ~/bin`

or `nano ~/bin/run.sh` and paste the run.sh code and ^O and ^X to create 
and then

`export PATH=~/bin:"${PATH}"`


and then to compile and run, you just need to do: 

`user@terminal:~$ run.sh program.c`

You can also rename the file to be just `run` and do

`user@terminal:~$ run program.c`
