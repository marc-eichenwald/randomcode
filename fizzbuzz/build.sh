#!/bin/bash

#just a simple build and link of the input files
nasm fizzbuzz.s -L ELF64 
ld fizzbuzz.o -lc -I/lib/ld-linux-x86-64.so.2 -o fizzbuzz.exe
rm fizzbuzz.o