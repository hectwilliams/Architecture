#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern int hermes; 

/*
  Reduce the value of hermes at each loop iteration
*/
void attack_hermes () {

  hermes -=  (rand() % 10);
  printf("hermes attacked, altitude = %d\n", hermes);    

}

