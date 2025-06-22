#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

extern int hermes; 

/*
  Reduce the value of hermes at each loop iteration
*/
void attack_hermes () {

  for (int i =0; i < 10; i++) {
    sleep(1);
    hermes -=  (rand() % 10);
    printf("hermes attacked, altitude = %d\n", hermes);    
  }

}

