# CPractice
Short programs to practice C language.

fileValidation.c .

  This program calculates the length of a real number. The programs asks for input from file "in.txt".
  If input is incorrect or file could not be opened or read, the programs asks user to input a new file name.
  The number must be between 10 and 1000 with 5 digits at most, whole and fractional parts must be separated by a comma.

  This program mostly focuses on file validation.


linkedListMain.c && compress.h && compress.c .

  linkedListMain.c
    This program compresses a singly linked list, leaving only one node of the same value in a row.
    The program gets the list values from an input file with the name specified by the user.
  compress.h contains function declarations from compress.c  .
  compress.c contains three functions:
    1. Adding a node to a singly linked list.
    2. Compressing the list, leaving only one element of same value in a row.
    3. Deleting the linked list.
