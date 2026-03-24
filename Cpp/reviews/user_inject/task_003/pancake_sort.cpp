#include "pancake_sort.h"

/**
*/
void print (std::vector<int>&cakes) {
  
  std::cout << "Pancakes: " << cakes.size() << " --- :";

  for (const int& item: cakes) {

      std::cout << item << " ";
  } 

  std::cout << '\n';

}

/**
*/
void get_cakes_user(std::vector<int>&cakes) {

  int hotcake;

  int i = 0;

  while (true) {
  
    std::cout << "Add pancake to stack( Enter radius, Enter 0 to quit )\n: ";

    std::cin >> hotcake;

    if (!std::cin || hotcake < 0) {

      std::cin.clear();

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      continue;

    }
  
    if ( hotcake == 0) {

      break; 

    } else  {
      
      cakes.push_back(hotcake);

      if (cakes.size() == (static_cast<std::size_t>(i))) {

        std::cerr << ("Pot is full of cakes\n");

        break;

      }

    }
  }

}

/**
 * 
*/
void reset_terminal(){
  std::cout << "\033[2J\033[1;1H";
  std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pauses for 0.5 seconds helps show print prior to resetting terminal 
  std::cout << "\rWelcome to pancake sort\nSelect pankcake loading option\n1)User enter cakes\n2)Print pancakes\n3)Sort\n0)Shutdown \n:";  
}

/**
*/ 
void load_cakes(std::vector<int>& cakes) {

  int cake_radius;

  while (true) {

    reset_terminal();

    std::cin >> cake_radius;

    if (!std::cin) {
     
      std::cin.clear();

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      
      continue;
      
    }

    if (cake_radius == 0) {

      break;

    } else if (cake_radius == 1) {

      get_cakes_user(cakes);

    } else if (cake_radius == 2) {
     
      print(cakes);

    } else if (cake_radius == 3) {
   
      sort(cakes); 

    }

  }

}

/**
*/
void cook_pancakes() {
  
  // create pan
  std::vector<int> ps(10); // ps = pancake stack 
  ps.clear();

  // add cakes 
  load_cakes(ps); 

  sort(ps); 

}

/**
*/
void sort(std::vector<int>& cakes) {

  std::vector<int> fifo(cakes.capacity()) ;  // copy :( 

  std::size_t min_index;
  int min_value; 
  
  for (std::size_t i = 0; i < cakes.size(); i++ ) {

    fifo.clear();

    min_index = std::numeric_limits<std::size_t>::max();
    min_value = std::numeric_limits<int>::max();

    // find min (if min is at index i NOOP)

    for (std::size_t m = 0; m < cakes.size(); m++) {
    
      if ( m >= i && cakes[m] < min_value ) {
        min_index = m;
        min_value = cakes[m];
      } 
    
    }
 
    // min_index > base  index for subset of pankcakes    

    if (min_index != i) {

      while (cakes.size() != min_index) {
        auto item = cakes.back(); //copy object
        cakes.pop_back();  // release object
        fifo.push_back(item);  // copy object into fifo
      }

      // empty fifo 

      for (auto item: fifo) {
        cakes.push_back(item);
      }
    
      fifo.clear();
 
      /*flipped from i-th  pancake*/

      // empty stack of cakes into fifo

      while (cakes.size() != i) {
        auto item = cakes.back();
        cakes.pop_back();
        fifo.push_back(item) ;  
      }
   
      // empty fifo into pan 

      for (auto item: fifo) {
        cakes.push_back(item);
      }

    }

  }
  
  print(cakes);

}
