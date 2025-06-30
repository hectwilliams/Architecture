#include <iostream>
#include <ipc_simple.h>

int main(int argc, char ** argv) {

  char *str;
  
  if (argc == 2) {
    
    str = *argv;
    
    str += strlen(str) + 1; // read second argument 
    
    if (std::strcmp(str, "producer") == 0) {
      
      producer(); 

    } else if (std::strcmp(str, "consumer") == 0) {
      
      consumer(); 
      
    } else if (std::strcmp(str, "garbage") == 0) {

      garbage();

    }

  }

}