#include <iostream> 
#include <fstream>
#include <vector>
#include <SimpleProcessor.h>
#include <regex>

/*
  
  Layman_Digital_Processor Class performas math operation on time data samples from a csv file

*/

int main() {

  char buffer[BUFFER_SIZE];

  std::ifstream file;
  
  int counter = -1; 
  
  std::regex regex_pattern(".+,");
  
  std::vector<double> *data_in = new std::vector<double>(100e3, 0.0);
  
  file.open("time.csv", std::ifstream::in);
  
  file.getline(buffer, BUFFER_SIZE);

  while (file.good()) {
    
    if (counter >= 0) {

      data_in->at(counter)= std::stod( std::regex_replace(buffer, regex_pattern , "") );
      
    }
    
    file.getline(buffer, BUFFER_SIZE);
    
    counter += 1;
    
  }
  
  data_in->resize(NUM_SAMPLES);
  
  SimpleProcessor<double> proc( *data_in); // use default Template Type

  // proc.print_stdout();

  proc.dft();

  file.close(); 

  delete data_in;

}