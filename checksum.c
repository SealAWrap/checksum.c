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
  int quotient, remainder; //retval;
  byte checksum; 
  byte complement;
  byte buffer[10];
  //int fd = open( STDIN, O_RDWR )

  /* the following is the prototype for the read system call */
  /* int read(int fildes, void *buf, size_t nbyte);  */
  read(STDIN_FILENO, &buffer, 10);

  for (int i = 0; i < count; i++) {
    printf("%d\n", buffer[i]);
    
  } 

  while (count > 0) {  
    if (count == 5) {
      checksum = buffer[count];
    }else{
      sum += buffer[count];
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