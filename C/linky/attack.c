#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#if TARGET_OS_TESTY
  #define NAME "Hector"
#endif

extern int hermes;
extern void rand_attack(); 

void attack () {
  
  for (int i =0; i < 10; i++) {
    sleep(1);
    rand_attack();
    printf("attacker sees hermes %d\n", hermes);    
  }

}