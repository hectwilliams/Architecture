#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h> 

enum Bool { FALSE = 0,  TRUE = 0 };

typedef struct {
  char name[100];
  enum Bool hasAccessToAirspace;
  int num_of_events;
  void (*f_ptr)(); // function pointer for attack_hermes and hermes_fly
  
  pthread_mutex_t lock; 
} User;

