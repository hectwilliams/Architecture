#ifndef MMAP_H
#define MMAP_H 

#define MEMORY_SIZE 1024

#define MEMORY_SIZE_X_2 4096 

#define SHARE_MEM_NAME "/shm"
#define SHARE_MEM_NAME2 "/shmm"

#define MESSAGE_1 "HELLO"
#define MESSAGE_1_SIZE 5

#define MESSAGE_2 "DEADBEEF"
#define MESSAGE_2_SIZE 8

/*

  function:

    create_share_mem

  remarks:

    used with X_share_mem() sister functions. This particular function creates share memory, mem-maps to process, and write to memory 

*/

void create_share_mem ();

/*

  function:

    read_share_mem

  remarks:

    used with X_share_mem() sister functions. This functions reads memory mapped region 

*/

void read_share_mem();

/*

  function:

    clean_share_mem

  remarks:

    used with X_share_mem() sister functions. This particular function garbage collects resources connected with shared mem object 
*/

void clean_share_mem();

/*

  function :
  
    increae_mmap_share_mem

  remarks: 
    
    used with X_share_mem() sister functions. This particular function attempts to create a larger mmmapped region on an already memory maapped object  

*/

void increae_mmap_share_mem();
/*
  function:

    foo

  remarks:

    run in tandem with boo() to show the persistence of a shared object after an unlink system call if another process is still mapped to object

*/

void foo();

/*
  function:

    boo

  remarks:

    run in tandem with foo() to show the persistence of a shared object after an unlink system call if another process is still mapped to object
    
*/

void boo();

/*

  function:

    cleanup 

  input:

    ptr - process memory mapped region to shared object
  
    fd - process file descriptor reference to shared object

    pid - process id 

    name -  share object name 

    mem_size -  bytes available in memory mapping 

  remarks:

    used to garbage collection mmapped resources when complete 

*/

void cleanup( void *ptr , int fd, pid_t pid, const char * name, size_t mem_size) ;

void wait (int seconds);

#endif 
