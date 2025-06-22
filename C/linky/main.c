#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <hermes.h>

extern void attack_hermes(); 
extern void hermes_fly(); 


/*
  Shared thread task 
*/
void * runner (void * arg){
  
  // cast void pointer to User pointer
  User *user = (User*) arg;
  
  if (user->hasAccessToAirspace) {
    printf("%s has access to airspace\n", user->name);
  } else {
    printf("%s does not have access to airspace\n", user->name);
  }
  
  user->f_ptr();

  return NULL;
}

int main() {
  
  pthread_t thr1, thr2;

  void *thr1_attr, *thr2_attr;

  thr1_attr = NULL;
  thr2_attr = NULL;

  User user1;
  User user2;
  
  user1.hasAccessToAirspace = TRUE;
  strcpy(user1.name, "Clark Kent");
  user1.f_ptr = hermes_fly;
  
  user2.hasAccessToAirspace = FALSE;
  strcpy(user2.name, "Darkseid");
  user2.f_ptr = attack_hermes;

  pthread_create(&thr1, thr1_attr, runner , &user1 );
  pthread_create(&thr2, thr2_attr, runner, &user2 );

  // wait for threads 
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

}