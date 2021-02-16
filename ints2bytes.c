#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define max_int (255)
#define byte char


int main (int argc, char * argv[], char ** envp) {

   int input;
   byte value;
   while  ( ! feof(stdin) ) {
     scanf("%d", &input);
     if (input > max_int) {
       fprintf(stderr, "Error in input!\n");
       exit(1);
     }
     value = (byte) input;
     write(1, &value, sizeof(byte));
  }
}