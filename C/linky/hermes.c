#include <stdlib.h>
#include <stdio.h>

int hermes = 0;

/*
  Increases value of hermes by a value between 0 and 10 st each loop iteration
*/
void hermes_fly() {

  hermes += rand() % 10;
  printf("hermes altitude = %d\n", hermes);    

}