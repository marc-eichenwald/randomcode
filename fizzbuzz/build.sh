#!/bin/bash

#just a simple build and link of the input files
bflag=
cflag=
while getopts c:b flag
do
    case $flag in
	  b) bflag = true;;
	  c) cflag = true;;
      esac
done
if [(bflag && cflag) || (!bflag && !cflag)]; then
   printf "Usage: %s [FLAG]\n" $0
   printf "-b\t build\n"
   printf "-c\t clean\n"
   printf "select one and only one flag\n"
   exit 2
fi
if [bflag]; then
    nasm -f LIB64 fizzbuzz.s
    ld fizzbuzz.o -lc -I/lib/ld-linux-x86-64.so.2 -o fizzbuzz.exe
    rm fizzbuzz.o
    exit 0
fi
if [cflag]; then
    rm fizzbuzz.exe
    exit 0
fi
