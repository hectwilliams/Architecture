#include <iostream>
#include <random>
#include <chrono> 
#include <cassert>
#include "lsfr.h"

const std::chrono::milliseconds ms  {3}; // 3 millisecond sample time 
const std::chrono::microseconds us =  ms; // micro ticks in 3ms   
const std::chrono::nanoseconds ns = ms; // nano ticks in 3ms   

void ticks_second(std::chrono::seconds s) {
  std::chrono::duration<double, std::ratio<1, 1000>> freq_1KHz_3ms (ms); // 1KHz ticks in 3ms
  std::chrono::duration<double, std::ratio<1, 1000>> freq_1KHz_4(4.5); // 4.5 1KHz ticks
  std::cout << " Number of 1KHz ticks in 3 ms: " << freq_1KHz_3ms.count() << '\n';
  std::cout << " 4.5 ticks of 1KHz clock " << freq_1KHz_4.count() << '\n';
  std::cout << " Number of us ticks in 3ms: "  << us.count() << '\n';
  std::cout << " Number of ns ticks in 3ms: "  << ns.count() << '\n';
}

int main() {
  
  const auto now_steady_clk = std::chrono::steady_clock::now(); 
  auto now_system_clk = std::chrono::system_clock::now();
  auto steady_clk_count = now_steady_clk.time_since_epoch().count(); 
  auto system_clk_count = now_system_clk.time_since_epoch().count(); 
  std::time_t t_c = std::chrono::system_clock::to_time_t(now_system_clk);
  std::cout  << "system.now date: " << std::ctime( &t_c ) ; 
  std::cout << "system ticks: " << steady_clk_count << '\n';
  std::cout  << "steady.now date: "  << "Nonexistent, as steady clock is ticks since last system boot" << '\n'  ;  
  std::cout << "steady ticks: " << steady_clk_count << '\n'; 
 
  /* 
  using product = std::ratio_multiply < std::ratio<1>, std::micro>;
  const double ratio_value = static_cast<double>(product::num) / product::den;
  std::cout  << product::num << '/' << product::den << '\n';
  std::cout  << ratio_value << '\n';
  */
  
  // Mersenne Twister PRNG
  std::cout << "\nMERSENNE PRNG\n\n";
  std::mt19937 mt{static_cast<std::mt19937::result_type>(steady_clk_count)}; 
  
  // 12 sided die - uniform distribution 
  std::uniform_int_distribution die12{1, 12};
  
  for (int i = 1; i <= 100; i++) {
    std::cout << die12(mt) << '\t';
    if (i % 6 == 0) // no remainder  
      std::cout << '\n';
  }
  std::cout << '\n';
  // LSFR sequence     
  std::cout << '\n';
  lsfr();

} 
