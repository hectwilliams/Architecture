#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int hermes = 0;

void rand_attack() {

  hermes -= (RAND_MAX % 20);

}

void fly() {

  for (int i =0; i < 10; i++) {
    sleep(1);
    printf("tick\t hermes=%d\t rand_max=%d\n", hermes, RAND_MAX);    
    hermes = rand();
  }

}


// | command/flag  | Descr   | Example    | Note |  
// |------------|------------|------------|------|
// | Row 1 Data | Row 1 Data | Row 1 Data |------|
// | Row 2 Data | Row 2 Data | Row 2 Data |------|
// | Row 3 Data | Row 3 Data | Row 3 Data |------|