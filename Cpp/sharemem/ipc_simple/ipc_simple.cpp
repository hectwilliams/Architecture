#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <thread>
#include <string>
#include <csignal>
#include <cstring> 
#include <ipc_simple.h>


void producer () {
  
  // Generate unqiue IPC key 

  key_t key = ftok(IPC_UNIQUE_NAME, IPC_PROJ_ID);

  // Create shared memory segment 
  
  int shmid = shmget(key, SHARE_MEM_BYTES, IPC_CREAT | 0666); 


  // Attach shared memory segment to calling process's address space 
  
  char * str = (char *) shmat(shmid, nullptr, 0);

  std::cout << shmid << std::endl; 
  
  // writes bytes to memory 
  memcpy(str, "DEADBEEF", 9);

  memcpy(str + 9, "BEEFDEAD", 9);

  // Detach shared memory from process address space 
  
  shmdt(str);

}

void consumer () {

  key_t key = ftok(IPC_UNIQUE_NAME, IPC_PROJ_ID);

  int shmid = shmget(key, SHARE_MEM_BYTES, 0666); 

  char * str = (char *) shmat(shmid, nullptr, 0);

  std::cout << "key " << key << " id " << shmid << std::endl; 

  std::cout << "word 1: " << str << std::endl; 
  
  std::cout << "word 2: " << str + 9 << std::endl; 

  shmdt(str);

}

void garbage () {
  
  key_t key = ftok(IPC_UNIQUE_NAME, IPC_PROJ_ID);

  int shmid = shmget(key, SHARE_MEM_BYTES, 0666); 

  if (shmid != -1) {
  
    // Destroy shared memory segment 
    
    shmctl(shmid, IPC_RMID, nullptr);

    std::cerr << "deleted  shared memory"  << std::endl; 

  } else {

    std::cerr << "error, unable to find shared memory "  << std::endl; 

  }

}