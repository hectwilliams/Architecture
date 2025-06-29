#include <iostream> 
#include <vector> 
#include <SimpleProcessor.h>
#include <complex>
#include <fstream> 
#include <regex>
#include <system_error>

template<>
SimpleProcessor<double>::SimpleProcessor( std::vector<double> &data_in) : data(data_in){

  std::cout << "processor rcvd doubles" << std::endl; 

}

template<>
SimpleProcessor<int>::SimpleProcessor( std::vector<int> &data_in) : data(data_in){

  std::cout << "processor rcvd int" << std::endl; 

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
  
  //computes discrete fourier transform and writes data to out.txt

  std::ifstream some_file_csv;
  
  std::string s;

  double real, imag, x_m_abs; 

  std::complex< double> x_m;

  double max_value = std::numeric_limits<double>::min() ;

  unsigned N = static_cast < unsigned >(data.size());
  
  std::vector< double> *pad = new std::vector< double>(N, static_cast< double>(0)) ;

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

  for(std::vector< double>::iterator it = pad->begin(); it != pad->end(); ++it) {
    
    s = std::to_string(20*std::log10(*it/max_value)) + "\n";
    
    some_file_csv.rdbuf()->sputn(s.c_str(), s.length());

  }

  delete pad;
  
}

void run_simple_processor() {

  /*
    Actions 

      1. create and truncate out.txt file

      2. dynamically store time.csv column-2 data into vector object

      3. Use simple processor to run FFT on data 

      4. magnitude log normalize FFT processed data 

      5. write data in step 4 to out.txt file 

      6. delete dynamically allocated resources 

  */

  char buffer[BUFFER_SIZE];

  std::ifstream file;

  int counter = -1;

  std::regex regex_pattern(".+,");

  std::vector<double> *data_in = nullptr;
  
  try {
    
    data_in = new std::vector<double>(NUM_SAMPLES, 0.0);
    
    file.open("time.csv", std::ifstream::in);

    file.getline(buffer, BUFFER_SIZE);

    while (file.good() && counter < NUM_SAMPLES) {
      
      if (counter >= 0) {

        data_in->at(counter)= std::stod( std::regex_replace(buffer, regex_pattern , "") );
        
      }
      
      file.getline(buffer, BUFFER_SIZE);
      
      counter += 1;
      
    }

    SimpleProcessor<double> proc( *data_in); 

    // proc.print_stdout();

    proc.dft();

    file.close(); 
    
  } catch(const std::system_error &e) {
    
    std::cerr << "Caught system error: " << e.what() << '\n';
    
  }

  if (data_in) {

    delete data_in;

  }

}
