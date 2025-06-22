#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

extern void attack(); 
extern void rand_attack(); 
extern void fly(); 

int main() {
  fly();
  attack();
}