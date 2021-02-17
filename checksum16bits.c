/********************************/
/* Program Name:Checksum 16-bits*/
/* Author: Jeovany J. Guillen   */
/* Date: Feb. 9, 2021           */
/********************************/
/* Description:                 */
/* Validation Checks: needs to make sure the input numbers don't go out of bound 65535*/
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
//#include <fcntl.h>
#include <sys/types.h>
//#include <sys/uio.h>
//#include <unistd.h>


#define max_int (65535)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  int quotient, remainder; //retval;
  byte checksum; 
  byte complement;
  byte header[10];
  //int fd = open( STDIN, O_RDWR )

  /* the following is the prototype for the read system call */
  /* int read(int fildes, void *buf, size_t nbyte);  */
  read(STDIN_FILENO, &header, 10);

  for (int i = 0; i < count; i++) {
    printf("%d ", header[i]);
    printf("\n");
  } 
  printf("\n");

  for (int i = 0; i < count; i++) {  
    if (i == 5) {
      checksum = header[i];
      printf("Checksum has passed\n");
    }else{
      sum = sum + header[i];
      printf("%d\n", sum);
    }
  }
  quotient = sum / (max_int + 1);
  remainder = sum % (max_int + 1);
  printf("Printed quotient %d\n", quotient);
  printf("Printed remainder %d\n", remainder);
  sum = quotient + remainder;
  printf("sum %d\n\n", sum);
  complement = max_int - sum;
  

  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}/*end of main*/