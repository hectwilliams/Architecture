#include "tower_of_hanoi.h"

/**
 * @details 
 * Top level for solving TowerOfHanoi solver.
 *
 * Caller calls the overloaded or alias version which handles logic and compute.
*/
void toh() {
  
  toh(TowerOfHanoi{});
}

/**
 * @details
 * Finds solution for toh and prints the number of steps required to find a solution.
 *   
*/
void toh(const TowerOfHanoi& t) {
  
  static int minimum_moves_to_solve {0};

  if ( valid_state(t) ) {
        
    std::string current_state = t.tower1 + "," + t.tower2 + "," + t.tower3 + '\n';
      
    if (t.tower3  == "abc") {

      int n = nlines(t.states) ;      
  
      if (minimum_moves_to_solve == 0 || n < minimum_moves_to_solve ) {
        
        minimum_moves_to_solve = n; 
        std::cout <<  n  << "  moves to solve\n";
        std::cout << t.states  << "\n -----\n";

      }
           
    } else {
    
      if(!t.tower1.empty()) {

        if ( valid_disk_move( t.tower1[0], t.tower2) ) {
          // Pop Tower 1 stack and add to Tower 2
          toh( TowerOfHanoi{t.tower1.substr(1), t.tower1[0] + t.tower2 , t.tower3, t.states + current_state } ); 
        }
       
        if (valid_disk_move(t.tower1[0], t.tower3) ) {
          // Pop Tower 1 stack and add to Tower 3
          toh( TowerOfHanoi{t.tower1.substr(1),  t.tower2 , t.tower1[0] +  t.tower3, t.states + current_state } ); 
        } 
      }

      if(!t.tower2.empty()) {
       
        if ( valid_disk_move( t.tower2[0], t.tower1) ) {
          // Pop Tower 2 stack and add to Tower 1
          toh( TowerOfHanoi{t.tower2[0] + t.tower1,  t.tower2.substr(1) , t.tower3, t.states + current_state  } );
        } 
     
        if (valid_disk_move(t.tower2[0], t.tower3) ) {
          // Pop Tower 2 stack and add to Tower 3
          toh( TowerOfHanoi{t.tower1,  t.tower2.substr(1) , t.tower2[0] +  t.tower3, t.states + current_state } );
        }
      }

      if(!t.tower3.empty()) {
       
        if ( valid_disk_move( t.tower3[0], t.tower1) ) {
          // Pop Tower 3 stack and add to Tower 1
          toh( TowerOfHanoi{t.tower3[0] + t.tower1 , t.tower2 , t.tower3.substr(1), t.states + current_state  } );
        } 
   
        if (valid_disk_move(t.tower3[0], t.tower2) ) {
          // Pop Tower 3 stack and add to Tower 2
          toh( TowerOfHanoi{t.tower1,  t.tower3[0] + t.tower2 ,  t.tower3.substr(1), t.states + current_state  } );
        }
      }   

    }

  }  
}

/**
 * @details 
 *
*/
bool valid_disk_move(const char& c, const std::string& dest) {
 
  if ((dest.empty()) || (dest[0] > c)) {

   return true;
  }

  return false;
}

/**
 * @details
 *
 * std::string.find method is used to find current_state in scratchpad report.
 * If report doesn't have the current state written in scratchpad, the state will be added to report.
*/
bool valid_state(const TowerOfHanoi& t) {
  
  std::string current_state = t.tower1 + "," + t.tower2 + "," + t.tower3 + '\n';

  if ( t.states.find(current_state) == std::string::npos ) {
  
    return true;    
  }

  return false;
}

/**
 * @details
 *
*/
int nlines( const std::string& s) {

  int count = 1; // implementation stops when calle Toh object contains solved state. Initiation of count = 1 compensates for missed step. 
 
  for (int i = 0; i < s.size(); i++) {
    count += static_cast<int>(s[i] == '\n');
  }

  return count;
}
