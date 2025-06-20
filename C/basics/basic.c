#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "basic.h"
#define NUMBER_OF_NAMES 4
#define NAME_LENGTH 100

int main() {

  /*
    basic string operations
  */

  {

    const char message[100] = "the";
    printf("sizeof: message %lu\n", sizeof(message)); // user request 100 bytes, system provides with last byte equal to null termination
    printf("strlen: message %lu\n", strlen(message)); // number of characters before null termination 
    printf("strlen: message %d\n", message[99] == '\0') ; // test for null termination
    printf("strlen: message %d\n\n\n", message[3] == '\0') ; // test for null termination (system provides null termination after byte string)
  }


   /*
    name_sorter
  */
  {

    void name_sorter( char  *names, int num_of_names, int size);
    
    char list_of_names[NUMBER_OF_NAMES][NAME_LENGTH + 1]  = { 
      "Diddy Kong",
      "Mario",
      "Luffy",
      "Adam"
    };
    
    name_sorter ( (char *)list_of_names, NUMBER_OF_NAMES, NAME_LENGTH );
    print_names( (char *)list_of_names, NUMBER_OF_NAMES, NAME_LENGTH);
    
  }



    return 0;
  }