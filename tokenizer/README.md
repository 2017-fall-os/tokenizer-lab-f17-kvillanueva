Outline for README demonstrated by Ana Garcia and Alejandro Bladerrama
# os-tokenizer-lab-1
# Source code by Kristian Villanueva

## Introduction

•Lab1 reads in strings of tokens input in the command line by the user. At the beginning of the program, specific test cases are run prior to requesting user input.The main function in test.c sends the input as a character pointer to mytoc.c. Once in mytoc.c the tokens are counted and the specific length of each token is counted. The tokens are then coppied into a doulbe pointer character variable, printed, and returned to main. Once in main the memory is freed and the next user input is requested. Typing "exit" quits the program.

## Code Directory

•test.c: Reads in user input and sends the whole string to mytoc()
•mytoc.c: Separates the whole string into separate tokens based on entered
delimiter 
•mytoc.h: Header file that declares the mytoc() function in mytoc.c
•Makefile: contains compilation and run instructions for test.c and mytoc.c

## Compilation and run insturctions

•Compilation: With Makefile in the same directory, type make to compile files
•Run: After compilation, type ./test, and the program will run
