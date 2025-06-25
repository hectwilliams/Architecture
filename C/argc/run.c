#include <stdio.h>
#include <string.h>
#include <run.h>

int test() {
  
  static int count = 0; 

  count+=1;

  return count; 

}

int main (int argc, char **argv) {
  char *ptr; 
  int offset = 0;
  int *num_ptr;

  for (int i =0; i < argc; i++) {
    
    // point to new space-delimited argument 
    ptr = *argv + offset;

    offset += strlen(ptr) + 1; 

    printf( "%s \n",(ptr));

  }

  test();
  test();

  printf( "0x%x \n", test());
  

}