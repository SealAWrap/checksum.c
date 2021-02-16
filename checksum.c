/********************************/
/* Program Name:Checksum        */
/* Author: Jeovany J. Guillen   */
/* Date: Feb. 9, 2021           */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
//#include <fcntl.h>
#include <sys/types.h>
//#include <sys/uio.h>
//#include <unistd.h>


#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  int quotient, remainder, retval;
  byte checksum; 
  byte complement;
  byte header[10];

  /* the following is the prototype for the read system call */
  /* int read(int fildes, void *buf, size_t nbyte);  */
  //int read(int fildes, void *buf, size_t nbyte);
  retval = read(STDIN_FILENO, (void *) &header, 10); 
  while (count > 0) {  
    if (count == 5) {
      checksum = header[count];
    }else{
      sum += header[count];
    }
    count--;
  }
  quotient = sum / (max_int + 1);
  remainder = sum % (max_int + 1);
  sum = quotient + remainder;
  complement = max_int - sum;
  

  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}/*end of main*/