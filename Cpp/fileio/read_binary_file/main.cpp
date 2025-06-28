#include <iostream>
#include <fstream>
#include <string> 
#include <random> 
#include <unistd.h>
#include <main.h> 

void write_1600_random_bytes( const std::ifstream &stream) {
  
  // writes 1600 random bytes having values between 65 and 90 to file stream 

  std::random_device rand_dev; 
  
  std::default_random_engine rand_gen(rand_dev());  
  
  std::uniform_int_distribution<> distr_int(65, 90); 

    
  char *ptr_c = new char[BYTES_1600];

  for (int i = 0; i < BYTES_1600; i++) {

    char c = static_cast<char>(distr_int(rand_gen));

    ptr_c[i] = c;

  }

  stream.rdbuf()->sputn(ptr_c, BYTES_1600);

  delete[] ptr_c; 

}

void gen_file( const std::ifstream &stream, const std::string filename) {

  // generates random bytes with occasional unique 8 byte sequence
    
  std::random_device rand__dev; 
  
  std::default_random_engine rand_gen(rand__dev());  
  
  std::uniform_real_distribution<double> distr_uniform(0.0, 1.0); 

  double rand;

  for (int i =0; i < 10; i++) {

    rand = distr_uniform(rand__dev) ;
    
    if (rand < 0.5) {
      
      stream.rdbuf()->sputn( (char *) CHECKID, sizeof((char*) CHECKID ));

    } else {
      
      write_1600_random_bytes(stream);
    
    }
    
  }

}

void find_deadbeef(const std::ifstream &stream) {
  
  // slides an 8 byte window across binary sequences and writes each sliding snapshot to a file 

  int ret_count; 
  
  std::ifstream file;

  char buf_window [SLIDING_WINDOW_BUFFER_SIZE + 1]; // window[8] = null 
  
  int pos = 0;
  
  std::string filename= "dummy_sliding.txt";

  std::size_t size = stream.rdbuf()->pubseekoff(0, stream.end);

  std::string line; 

  buf_window[SLIDING_WINDOW_BUFFER_SIZE] = '\0';
  
  try {

    file.open(filename, std::fstream::out | std::fstream::trunc );
  
  } catch (...) {

    std::cout << "interrupt " << std::endl;

  }
  
  // sliding window 
  do {  
    
    stream.rdbuf()->pubseekpos( (std::streampos) pos);

    ret_count = stream.rdbuf()->sgetn(buf_window, SLIDING_WINDOW_BUFFER_SIZE);

    if (ret_count != SLIDING_WINDOW_BUFFER_SIZE) {

      for (int i = 7; i >=  SLIDING_WINDOW_BUFFER_SIZE - (SLIDING_WINDOW_BUFFER_SIZE - ret_count) ; i--) {
        
        buf_window[i] = '\0';

      }

    }
    
    pos = pos + 1; 
    
    line = std::string(buf_window)  + "\n";
    
    file.rdbuf()->sputn(line.c_str(), line.length());

    // std::cout << buf_window << std::endl; 

  } while (ret_count > 0);

  file.close();

}

int main() {

  std::ios_base::openmode mode = std::fstream::out | std::fstream::trunc; // WRITE MODE | OVERWRITE FILE IF NEEDED
  
  std::string filename= "dummy.txt";

  std::ifstream file;
  
  try {

    file.open(filename, mode );
  
  } catch (...) {

    std::cout << "interrupt " << std::endl;

  }

  if (file.is_open()) {
     
    gen_file(file, filename);
    
    find_deadbeef(file);
    
    file.close();

  }

}
