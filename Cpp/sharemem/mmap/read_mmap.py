from multiprocessing import shared_memory
import numpy as np

MEMORY_SIZE = 1024
PAGE_SIZE = 4096

if __name__ == "__main__":
  
  shm = shared_memory.SharedMemory("shm", size=MEMORY_SIZE, track=False)

  array = np.ndarray(MEMORY_SIZE, dtype=np.int8, buffer=shm.buf)

  print(array.tobytes()) 

  print(array.tobytes().decode('utf-8')) 

  shm.close() # close file descriptor 

  # shm.unlink() # delete the shared memory block 

