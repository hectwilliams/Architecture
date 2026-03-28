/*
 
 Radix Sort :) 

 Author: H.W 
*/

#include "radix_sort.h"

bool sort_done_cb ( const Node * node, int N) {
  int count = 0;
  while (node) {
    node = node->next; 
    ++count;
  }
  return N == count; 
}

Array7 radix_sort(Array7 arr, const std::function<bool(const Node*, int)>& callback ) {

  Array7 result{};
  std::array<ArrLL,2> lls{}; // 2 storage blocks 
  bool state{};
  bool state_tmp{};
  ArrLL sel,sel2; // storage
  int digit; 
  int factor_10 = 1;  
  Node *node, *prev; 
  int rindex;

  factor_10 = 1;

  while(true) {
    
    if (factor_10 == 1) {
      
      // scan arr parameter and load storage 

      for(std::size_t i = 0; i < arr.size(); ++i) {
  
        digit = (arr[i] /  factor_10) % 10  ;
   
        add_to_storage(lls[static_cast<int>(state)], arr[i], digit);
      }   
    

    } else {

      // free secondary  storage ( one storage block processes while the other is cleared ) 

      clear_arrll(lls[static_cast<int>(!state) ]);

      for (std::size_t i = 0; i < 10; ++i) {

        node = lls[static_cast<int>(state)][i] ;
        
        while (node) {
          
          prev = node;
           
          node = node->next; 

          digit = (prev->value /factor_10) % 10;
    
          add_to_storage(lls[static_cast<int>(!state)], prev->value, digit);
          
        }
  
      }

      state = !state;       
            
    }

    factor_10 *= 10; 

    if (callback( lls[static_cast<int>(state)][0]   , 7))  {
    
      // copy sorted linked list to result 
   
      node = lls[static_cast<int>(state)][0];
      rindex = 0;
      while(node) {
        result[rindex++] = node->value;
        node = node->next; 
      }
     
      break;
    }

  }

  return result; 

}

void add_to_storage(ArrLL& sel, int value, int digit_index) {


  if ( !sel[digit_index] ) {
        
    // head of linked list in array slot

    sel[digit_index] = new Node{value};
          
  } else {
        
    // extend linked list in array slot

    Node* node = sel[digit_index];

    while(node->next) {

      node = node->next;
 
    }

    node->next = new Node{value};

  }

}

void clear_arrll(ArrLL& storage) {
  
  Node * prev;
 
  Node * node;

  for (int i = 0; i < 10; i++) {

    node = storage[i];
    
    while(node) {

      prev = node; 
      node = node->next; 
      delete prev; 
 
    }
   
   storage[i] = nullptr; // null pointers

  }

} 



