#include <iostream>
#include <cstring>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h> // file descriptor system header 
#include <unistd.h> // getpid()
#include <iomanip> // For std::hex
#include <ipc_mmap.h> 
#include <assert.h>
#include <chrono>
#include <thread>

void create_share_mem () {

    // create share mem object 

    int shm_fd = shm_open(SHARE_MEM_NAME, O_CREAT | O_RDWR, 0666);
    
    if (shm_fd < 0) {
      
      std::cout << " failed to create shared memory "  << std::endl;

      return;

    }

    // set size of memory 

    ftruncate(shm_fd, MEMORY_SIZE);

    // map process address region to shared object 
    
    void *ptr  = mmap(0, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED , shm_fd, 0);
    
    if (ptr != MAP_FAILED) {

      // write to memory region 1 

      const char *msg1 = "BUFFY THE VAMPIRE SLAYER";

      std::memcpy(ptr, msg1, std::strlen(msg1) + 1);

      std::cout << "address mmap 1: " << std::hex << ptr << std::endl;
      
      wait(10);
    }

}

void read_share_mem() {
  
  int shm_fd = shm_open(SHARE_MEM_NAME, O_RDONLY, 0666); // open shared mem object
  
  void *ptr  = mmap(0, MEMORY_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0); // map shared mem to address space 

  if (ptr != MAP_FAILED) {

    std::cout << std::hex << ptr << std::endl;

    std::cout << (char *) ptr << std::endl; 

    std::cout << (char *)  (  (void *)((char *)ptr + 24 + 1) ) << std::endl; 

  }

}

void clean_share_mem() {

  int shm_fd = shm_open(SHARE_MEM_NAME, O_RDWR, 0666);

  void *ptr = mmap(0, MEMORY_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
  
  if (ptr != MAP_FAILED) {
  
    cleanup(ptr,  getpid(), shm_fd, SHARE_MEM_NAME,  MEMORY_SIZE);
    
  }

}

void increae_mmap_share_mem() {
  
  int shm_fd = shm_open (SHARE_MEM_NAME, O_RDWR, 0666);

  void *ptr = mmap(0, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd , 0); 
   
  if ( ptr != MAP_FAILED) {
    
    std::cout << "attemtping to overwrite region" << std::endl; 

    std::memcpy(ptr, "DEADBEEFAA", 11);

    std::cout << (char *) ptr << std::endl; 

  } else {

    std::cout << " process failed to mapped to shared object " << std::endl; 

  }
   
}

void foo () {
  
  int counter = 0;

  void *ptr;
  
  int shm_fd = shm_open(SHARE_MEM_NAME2, O_CREAT | O_RDWR, 0666);
  
  ftruncate(shm_fd, MEMORY_SIZE);
  
  ptr = mmap(0, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

  std::memcpy(ptr, MESSAGE_1, MESSAGE_1_SIZE + 1);

  std::cout << getpid() << "(-process) using shared object" << std::endl; 

  while (counter < 5) {

    wait(3) ;
    
    counter += 1;

  }
  
  std::memcpy(ptr, "DEADBEEF", 9);

  cleanup( ptr , shm_fd , getpid() , SHARE_MEM_NAME2, MEMORY_SIZE);

}

void boo () {
  
  int shm_fd = shm_open(SHARE_MEM_NAME2, O_RDWR, 0666);
  
  void *ptr = mmap(0, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  
  if (ptr != MAP_FAILED) {

  std::cout << getpid() << "(-process) process using shared object" << std::endl; 

    while (strcmp((char *)ptr, "DEADBEEF") != 0) {
      
      wait(1) ;
      
    }

    cleanup(ptr,  shm_fd, getpid() , SHARE_MEM_NAME2, MEMORY_SIZE);

  }

}

void cleanup( void *ptr , int fd, pid_t pid, const char * name, size_t mem_size) {
  
  std::cout << pid << std::endl ;

  std::cout <<  "ummapping ..." << std::endl;

    // unmap to process 

  if (munmap(ptr, mem_size) == 0) {
    
    std::cout << "unmapped from process" << std::endl;
    
  }

  // close file descriptor

  if (close(fd) == 0) {
    
    std::cout << "closed shared memory file descriptor"<< std::endl;;
    
  }

  // remove shared memory object 

  if (shm_unlink(name)  == 0) {
    
    std::cout << "removed shared memory object"<< std::endl;;
    
  }

  std::cout << "  ... done" << std::endl;

}

void wait (int seconds) {

  std::this_thread::sleep_for(std::chrono::seconds(seconds));

}