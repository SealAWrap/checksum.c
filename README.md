# Checksum.c
### COMP122: Generating a checksum value using a buffer

```
check·sum | ˈCHekˌsəm |
noun
a digit representing the sum of the correct digits in a piece of stored or transmitted 
digital data, against which later comparisons can be made to detect errors in the data.
```


# Purpose:
Now that you have demostrated the ability to write a Java program to compute a checksum, your task is to write the same program in C. The algorithm, however, is slighlty different to perform the checksum incremently within a loop.  This algorthm was described in class.  Also within this implementation you must use a signal 'read' system call to obtain 10 bytes used as the input to the program. 

The purpose of this assignment is as follows:
  1. Introduce you to the C program language and to demostrate that because you know Java you already know a fair amount of C.
  1. Familize yourself with the 'make' utility used to maintain software projects.
  1. Establish an understanding of  OS system calls and the use buffers.


# Assignment:
1. Fork this repository as a new software project
1. Use 'git' as part of your software development process
1. Write a C program that computes a simple checksum of 10 8-bit integers.  
   * This program is *based* upon the calculation of the checksum value of a IPv4 header, defined by RFC791. 
   * The algorithm and calculations was presented in class and demostrated via the "checksum calc" spreadsheet.
1. Provide the URL of your project and a script file as the submission to this assignment.

Your C program should conform to the following specification:
  * Program name: checksum
  * Reads 10 bytes from standard input (stdin), using the 'read' system call
  * Interpets or casts each of these bytes as an integer value in the range of 0..2^8-1 (I.e., 0..255). 
  * Via a loop, examines each of these bytes in turn,
     * computes the running 1's complement sum for 8-bit numbers
     * saves the 6th byte into a variable called "checksum", and use the value of zero (0) instead for the calculation of the sum
  * Performs the one's complement of the final sum and saves this value to a variable called "complement"
  * Outputs the value of "checksum" and "complement" to standard output (stdout) via the printf C library call
  * If the value of "checksum" and "complement" are not the same, outputs the string "Error Detected!" to standard error (stderr).


### Minimum Validation Checks:
* I leave this up to you.  Document these validation checks as part of a summary documentation at the top of the program.


### Starter Code:

```
/********************************/
/* Program Name:                */
/* Author:                      */
/* Date:                        */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"

#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  byte checksum; 
  byte complement;

  /* the following is the prototype for the read system call */
  /* int read(int fildes, void *buf, size_t nbyte);  */
```

```
  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}
```


### Developement Process
You can develop this program using any editor of your choosing on any platform. During this process, you should beginning to integrate the use of git.

The following are suggestive steps:
* fork this github repository to create you own version of the software
* clone the repository onto your development computer
* REPEAT
   1. develop a incremental version of your code that works
   1. commit your work into your local repo
   1. push your work into your github repo
   1. take a break
* UNTIL complete

### Final Validate and Submission
To obtain credit for this assignment, you must ensure your program works correctly on ssh.sandbox.csun.edu.  This server is shared resource in which you can finalize you work and the professor can validate this work.  The final steps for validation are as follows:

* Clone your github repo onto ssh.sandbox.csun.edu
```
$ ssh ssh.sandbox.csun.edu
$ mkdir -p comp122 ; cd comp122              # Optional: create a subdirectory for comp122
$ git clone $URL                             # Clone your repo
$ cd checksum.c                              # Change to the correct working directory
$ make                                       # Use the make command to build all necessary software components 
```

* Test your program:
```
$ script checksum.typescript 
$ cat 156.txt | ints2bytes | checksum
$ cat 229.txt | ints2bytes | checksum
$ cat 81.txt  | ints2bytes | checksum
$ exit
```

* Submit your assignent to Canvas with the following information:
1. The URL to your github repo
1. The checksum.typescript file

# Program Enhancements:
1. Modify the program and your test cases to use 16-bit integers (i.e., input numbers can now be (I.e., 0..64k, or 0..65535)

# Other Information and Resources:
This program is based upon the structure if a IPv4 packet.  Although you do not need to understand this structure to complete this assignment, you may want to review some of the material associated with IPv4.  More information will be provided in the lecture.
* https://en.wikipedia.org/wiki/IPv4
* https://en.wikipedia.org/wiki/IPv4_header_checksum

### Notes:
* The IPv4 header utilizes a checksum field that is 16-bit quanity. This program reduces the size in half to a 8-bit quantity.  Correspondingly, the following changes are made to keep things consistent: 
* The IPv4 header, without any options, has a total size of 20 bytes. This program reduces the size in half to a 10 byte size.
* This checksum value is stored in the 11th & 12th byte of the IPv4 header. This program assigns its location to the 6th byte.


