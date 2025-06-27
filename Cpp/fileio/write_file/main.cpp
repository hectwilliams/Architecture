#include <iostream> 
#include <fstream>
#include <random>
#include <string>
#include <main.h>
#include <random>

void file_buffer(const std::ifstream &stream, const std::string &s) {
  
  // write to streams internal buffer 

  // ptr to buffer 
  std::filebuf *ptr_buffer = stream.rdbuf();
  
  // write byte(s) 
  // for (int i = 0; i < s.length(); i++) {
    // stream.rdbuf()->sputc(s[i]);
  // }

  // write byte string 
  stream.rdbuf()->sputn( s.c_str(), s.length() );

}

int main () {

  // random generator device  
  std::random_device rand__gen; 
  
  // seed generator 
  std::default_random_engine rand_gen(rand__gen());  
  
  // uniform 
  std::uniform_real_distribution<double> distr_uniform(0.0, 1.0); 

  double rand_uniform;
    
  std::ifstream file; 

  std::ios_base::openmode mode = std::fstream::out | std::fstream::trunc; // WRITE MODE | OVERWRITE FILE IF NEEDED
  
  std::string line;

  try {
    
    file.open( "scratchpad.txt", mode );
    
    for (int i = -1; i < NUMBER_OF_LINES; i++) {

      if (file.is_open()) {

        // random number 
        rand_uniform = distr_uniform(rand__gen);

        if (i == -1) {
          
          line = std::string("") + "index,value\n";

        } else {
          
          line = std::to_string(i) + "," + std::to_string(rand_uniform) + "\n";

        }

        file_buffer(file, line);

      }

    } 
    
    file.close(); 

  } catch(...) {

    std::cout << "caught an exception" << std::endl; 

  }

}
