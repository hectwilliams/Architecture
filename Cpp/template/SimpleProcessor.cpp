#include <iostream> 
#include <vector> 
#include <SimpleProcessor.h>


template<>
SimpleProcessor<double>::SimpleProcessor( std::vector<double> &data_in) : data(data_in){
  std::cout << "hello world" << std::endl; 
}