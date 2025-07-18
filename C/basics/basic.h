#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  1) create a list of name 

  2) pass list of names to name_sorter, name_sorter will modify list provided by caller 

  // NAME_LENGTH + 1 allow the system to provide us with access to all its memory (moving the termination char ahead)

*/
void name_sorter( char *names, int num_of_names, int size) {

  char buffer1[size + 1];
  char buffer2[size + 1];
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