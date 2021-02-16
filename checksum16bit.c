/********************************/
/* Program Name:Checksum 16-bit */
/* Author: Jeovany J. Guillen   */
/* Date: Feb. 9, 2021           */
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
  int read(int fildes, void *buf, size_t nbyte);

  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}/*end of main*/