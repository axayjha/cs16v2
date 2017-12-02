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

Download the stpath script from my shell script repo
https://github.com/axayjha/shellscripts/blob/master/stpath

Run

`user@terminal:~$ bash stpath stapth`


Go to the folder having run.sh
and do

`user@terminal:~$ stpath run.sh`

And you're done!



and then to compile and run, you just need to do: 

`user@terminal:~$ run.sh program.c`

You can also rename the file to be just `run` and do

`user@terminal:~$ run program.c`

```
.
├── Day 1
│   ├── Prog1-LinearSearch.c
│   ├── Prog2-BubbleSort.c
│   ├── Prog3-InsertionSort.c
│   ├── Prog4-SelectionSort.c
│   └── Prog5-BinarySearch.c
├── Day 2
│   ├── Prog1-digToNum.c
│   ├── Prog2-median.c
│   ├── Prog3-mode.c
│   └── Prog4-reverse.c
├── Day 3
│   ├── Prog1.c
│   ├── Prog2.c
│   ├── Prog3.c
│   ├── Prog4.c
│   └── stack.h
├── Day 4
│   ├── Prog1-LinearQueue.c
│   └── Prog2-CircularQueue.c
├── Day 5
│   ├── Prog1a-fact.c
│   ├── Prog1b-fact_tail.c
│   ├── Prog2-gcd.c
│   ├── Prog3a-fib_rec.c
│   ├── Prog3b-fib_no_rec.c
│   ├── Prog4-mul.c
│   ├── Prog5-ackermann.c
│   └── Prog6-towersofhanoi.c
├── Day 6
│   ├── Prog 1 - quicksort.c
│   └── Prog 2 - mergesort.c
├── Day 7
│   └── heapsort.c
├── Extras
│   ├── Linked List
│   │   ├── link.c
│   │   └── link.h
│   ├── mergesort.c
│   ├── queuelink.c
│   ├── quicksort.c
│   ├── Stack
│   │   ├── stack.c
│   │   └── stack.h
│   └── stacklink.c
├── README.md
└── run.sh

10 directories, 37 files


```
