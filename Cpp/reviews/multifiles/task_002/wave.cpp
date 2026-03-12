#include "wave.h"
#include <complex> 
#include <iostream>
#include <fstream>
#include <cassert>

constexpr int N {static_cast<int>(Wave::N)}; 

std::complex<double> fft_data[N] = {};

void load_csv() {

  std::ofstream outfile("data.csv");
 
  assert(outfile && "error csv");
  
  // header 

  outfile << "m"<< ", " <<  "real" << ", " << "imag" << std::endl  ; 

  // data

  for ( int m = 0; m < N; m++) {
  
    outfile << m << ","  << fft_data[m].real() << ","  << fft_data[m].imag() << std::endl  ;

  }
 
  outfile.close();

}

void generate_wave () {

  double x_in;
  std::complex<double> z{};
  
  for ( int m = 0; m < static_cast<int>(Wave::N) ; m++ ) {
    
    for (int n = 0; n < static_cast<int>(Wave::N); n++) {
     
      // two tone signal  

      x_in = 0.3*std::cos (Wave::w1 * (1/Wave::Fs) * n) +  std::cos (Wave::w2 * (1/Wave::Fs) * n )   ;
 
      // e^ (-j2pimn/N) - weight/correlator

      z.real( std::cos(2 * Wave::PI * m * n / N));
      z.imag(-std::sin(2 * Wave::PI * m * n / N));

      fft_data[m] += x_in * z;     
 
    }
    
  }
  
 
}
