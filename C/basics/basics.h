#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  sort list of names 

  Args:

    names - pointer to memory location with names  
    num_of_names - number of in memory location of names 
    size - number of characters per entry (null terminated not included in size)
 
*/
void name_sorter( char *names, int num_of_names, int size) {

  char buffer1[size + 1];
  char buffer2[size + 1];
  char tmp[size + 1];
  int null_not_included_in_size = 1;
  int effective_len = (size + null_not_included_in_size);

  // laymans bubble sort 
  for(int i = 0; i < num_of_names; i++) {
    for (int k = i + 1; k < num_of_names; k++) {

      // copy comparable values to buffer
      memcpy(buffer1, names + effective_len * i, effective_len);
      memcpy(buffer2, names + effective_len * k, effective_len);

      if (strcmp(buffer1, buffer2) > 0) {
        // swap, update names memory 
        memcpy(names + effective_len * i,  buffer2, effective_len);
        memcpy(names + effective_len * k, buffer1, effective_len);

        //clear buffers 
        memset(buffer1, 0, size);
        memset(buffer2, 0, size);

      }
    }
  }
}

void print_names( char *names, int num_of_names, int size) {
  char buffer1[size + 1];
  int null_not_included_in_size = 1;
  int effective_array_length = (size + null_not_included_in_size);

  for(int i = 0; i < num_of_names; i++) {
    memcpy(buffer1, names + (i * effective_array_length), effective_array_length);
      printf( "name %s\n" , buffer1  );
  }

}