#include <iostream> 
#include <vector> 

#ifndef SIMPLE_PROC_H
#define SIMPLE_PROC_H

#define PI 3.141
#define BUFFER_SIZE 512
#define NUM_SAMPLES 2048

template<class T> // default template 

class SimpleProcessor {
  
  protected:
    
    std::vector<T> &data; // protected member acquires 

  public:

    SimpleProcessor(std::vector<T> &data_in);

    void print_stdout();
    
    void dft();

};


/**

  function:

    dft_helper 

  input:

    data - vector list of rational numbers 

  remarks:

    helper function to handle all acceptable data types

 */
template< typename T>
void dft_helper(const std::vector<T> &data);


/**

  function:

    print_stdout_helper 

  input:

    data - vector list of rational numbers 

  remarks:

    helper function to handle all acceptable data types

 */
template< typename T>
void print_stdout_helper(const std::vector<T> &data);

#endif 