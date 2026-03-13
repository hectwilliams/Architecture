/*
  
  File: main.cpp 

  Purpose: Moves PPFM.csv column one E-Field data into vector object. Compute the derivative of the data and store in a new PPFM_D.csv file. A python script 
  will run on another process producing the plots of both the original E-Field and derivative of E-Field.   

*/

#include "constants.h" // constant refs
#include <iostream>
#include <cstdio> 
#include <string>
#include <cassert>
#include <regex>
#include <vector>
#include <fstream>

int main() {
  char buffer[100];
  std::string result;
  const char *cmd  {"wc -l PPFM.csv"};
  std::regex re("[0-9]+\\s{1}");
  std::smatch m;
  
  /*  Using system wc command to gather number lines */ 

  // run command 
 
  FILE* pipe = popen(cmd, "r"); 
  
  if (!pipe) {
    std::cerr << "popen() failed\n";
    return 1;
  }

  // non-immediate read 
  
  while(std::fgets(buffer, static_cast<int>(sizeof(buffer)), pipe ) != nullptr) 
   result += buffer; 

  // close proc pipe 

  if(pclose(pipe) != 0) 
    std::cout << "hello world" << '\n';
  
  std::regex_search(result, m , re);

  if (m.empty()) {
    std::cerr << "empty result" << '\n';
    return 1;
  }

  // read/store csv Electric Field samples 
  
  int n_lines { std::stoi(m[0]) } ;
  std::ifstream f_in(  constants::CSV_FILENAME  ); 
  if (!f_in.is_open()) {
    std::cerr << "csv read-ifstream " << '\n';
    return -1;
  } 

  std::string line;
  std::uint32_t index{0};
  std::vector<double>  data(n_lines - 1); // E-Field vector 
  re = std::regex("(.+),(.+),(.+),(.+)"); // reassign regex   

  while (std::getline(f_in, line)) {
    if (index !=0 ) {
      std::regex_search(line, m, re);
      data[index - 1] = std::stod(m[2]);
      //std::stod(m[2]); # column 1 (0 index)
      //std::stod(m[3]); # column 2   
      //std::stod(m[4]); # column 3
    }
    ++index; 
  }  

  f_in.close();

  // differentiator 
 
  index = 0;
  std::ofstream outfile_csv (constants::CSV_D_FILENAME);
  assert(outfile_csv && "error opening csv");
  std::vector<double>::const_iterator it;  
  double data_delta{0.0}; // midpoint between two samples 
  outfile_csv << index << "," << "E-Field" << '\n';
  
  for (it = data.cbegin(); it != data.cend(); ++it) {
    index = static_cast<int>(&(*it) - &(*data.cbegin()));
    
    if (index == n_lines - 1) {
      // back differntial approx
      data_delta  = data[index-1]  + data[index] / 2.0;
      outfile_csv << index << "," <<  data[index] - data_delta  << '\n';
    } else {
      // foward differential approx
      data_delta  = data[index]  +  data[index + 1] / 2.0;
      outfile_csv << index << "," << data_delta  - data[index]    << '\n';
    }
    ++index;
  }

  // call/exec python and run script  

  if(std::system("python3 script.py") != 0) {
    std::cerr << "Python error. Please ensure the following requirements:\n\t1)Script must be run from task_004(this) directory\n\t2) install numpy library\n\t3) install matplotlib\n";
    return -1; 
  }
  
}

