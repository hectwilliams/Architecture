
#ifndef IPC_SIMPLE
#define IPC_SIMPLE

#define IPC_UNIQUE_NAME "shmfile"
#define IPC_PROJ_ID 65
#define SHARE_MEM_BYTES 1024 

void producer();

void consumer();

void garbage();


#endif

