#include <iostream> 
#include <vector> 
#include <SimpleProcessor.h>
#include <complex>
#include <fstream> 

template<>
SimpleProcessor<double>::SimpleProcessor( std::vector<double> &data_in) : data(data_in){

  std::cout << "starting to process doubles" << std::endl; 

}

template<>
SimpleProcessor<int>::SimpleProcessor( std::vector<int> &data_in) : data(data_in){

  std::cout << "starting to process integers" << std::endl; 

}

template<>  
void SimpleProcessor<double>::print_stdout() {
  
  print_stdout_helper(this->data);

}

template<>  
void SimpleProcessor<int>::print_stdout() {
  
  print_stdout_helper(this->data);

}

template<> 
void SimpleProcessor<double>::dft() {

  dft_helper(this->data);

}

template<> 
void SimpleProcessor<int>::dft() {

  dft_helper(this->data);

}

template<typename T>
void print_stdout_helper(const std::vector<T> &data) {
  
  // iterates vector list argument 'data' and prints samples to stdout on a line-by-line basis

    for(int i =0; i< data.size(); i++)  {
    
    if ( (i % 4) != 0) {

      std::cout << std::to_string(data[i])  +  " ";

    } else {

      std::cout <<  data[i] <<  std::endl;

    }
    
  }

}

template<typename T>
void dft_helper(const std::vector<T> &data) {
  
  //computes discrete fourier transform and writes data to file fft_out.txt

  std::ifstream some_file_csv;
  
  std::string s;

  double real, imag, x_m_abs; 

  std::complex< double> x_m;

  double max_value = std::numeric_limits<double>::min() ;

  unsigned N = static_cast < unsigned >(data.size());
  
  std::vector<long double> *pad = new std::vector<long double>(N, static_cast<long double>(0)) ;

  try
  {
    some_file_csv.open("./out.txt", std::ifstream::trunc | std::ifstream::out);
    
  } catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
 
  for (int m = 0; m < N; m++) {
    
    // mth DFT component

    x_m = std::complex<  double>();
    
    for(int n = 0; n < N; n++) {
      
      // nth time sample

      // DFT MAC
      real = std::cos((2*PI*n*m)/N);
      
      imag = std::sin((2*PI*n*m)/N);
      
      x_m += std::complex<  double>(data.at(n) , 0.0) * std::complex<  double>(real, imag); // real_value * complex_value

    }

    x_m_abs = abs(x_m);
    
    if (x_m_abs > max_value) {

      max_value = x_m_abs;

    }

    pad->at(m) = x_m_abs;

  }
  
  // log normal  

  for(std::vector<long double>::iterator it = pad->begin(); it != pad->end(); ++it) {
    
    s = std::to_string(20*std::log10(*it/max_value)) + "\n";
    
    some_file_csv.rdbuf()->sputn(s.c_str(), s.length());

  }

  delete pad;
  
}

