#include <iostream> 
#include <ipc_mmap.h>
#include <cstring>

int main (int argc, char ** argv ) {

  char *arg = *argv;

  arg = arg + strlen(arg) + 1;

  if (argc != 2) {

    exit(0);

  }

  if ( strcmp(arg, "create") == 0 ) {
    
    create_share_mem ();

  } else if (strcmp(arg, "read") == 0) {

    read_share_mem ();

  } else if (strcmp(arg, "clean") == 0) {

    clean_share_mem();
  
  } else if (strcmp(arg, "1") == 0) { 

    foo();

  } else if (strcmp(arg, "2") == 0) { 

    boo();

  }


}