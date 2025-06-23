#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <hermes.h>
#include <unistd.h>

extern void attack_hermes(); 
extern void hermes_fly(); 

/*
  Shared thread task by each user 
*/
void * runner (void * arg){
  
  User *user = (User*) arg;
  int iterations = user->num_of_events;

  if (user->hasAccessToAirspace) {
    
    printf("%s has access to airspace\n", user->name);
  
  } else {
    
    printf("%s does not have access to airspace\n", user->name);
  
  }
  
  if (iterations < 0 || iterations > 20) {
    
    iterations = 20;
  
  }

  for (int i = 0; i < iterations; i++) {
    
    pthread_mutex_lock(&user->lock);  
    user->f_ptr();
    usleep(10000); // 10 ms
    pthread_mutex_unlock(&user->lock);
  
  }

  return NULL;
}


int main() {
  pthread_mutex_t lock; 
  pthread_t thr1, thr2;

  void *thr1_attr, *thr2_attr;

  thr1_attr = NULL;
  thr2_attr = NULL;

  User user1;
  User user2;
  
  pthread_mutex_init(&lock, NULL);

  user1.hasAccessToAirspace = TRUE;
  strcpy(user1.name, "Clark Kent");
  user1.f_ptr = hermes_fly;
  user1.num_of_events = 10;
  user1.lock = lock;
  
  user2.hasAccessToAirspace = FALSE;
  strcpy(user2.name, "Darkseid");
  user2.f_ptr = attack_hermes;
  user1.num_of_events = 10;
  user2.lock = lock;

  pthread_create(&thr1, thr1_attr, runner, &user1 );
  pthread_create(&thr2, thr2_attr, runner, &user2 );

  // wait for threads 
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  // destroy mutex
  pthread_mutex_destroy(&lock);

  
}