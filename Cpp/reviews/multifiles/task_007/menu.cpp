#include "menu.h"


/**
 * @details
 * Implementation tests validity of user input. Input errors are handled quietly and the function will re-print the menu.
 * Three options available: Insert (ID = 1) , Print ( ID = 2) , Quit (ID = 3).
 * Quiting will deallocate all heap allocated node objects. 
 */

template <typename T>
int menu_helper(int& id, Tree<T>& tree) {  

  while (true) {
  
    std::cout << "\nOptions Menu:\n1)Add value to tree\n2)Print tree\n3)Quit\nSelect by entering digit: ";
   
    std::cin >> id;
  
    if (!std::cin) /*compiler failed to convert rcvd to integer*/ {
   
      // reset std::cin flags

      std::cin.clear(); 

      // clear buffer

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
    } else {
     
      T v {};
      switch(id) {
      case Insert:
        std::cout << "Add value (i.e. an integer): ";
        std::cin >> v;
        if (std::cin) {
          insert<T>(v, tree);
        }
        continue;
      case Print:
        print<T>(tree);
        continue; 
      case Stop:
        delete_tree<T>(tree);
        return -1;
      default:
        std::cout << "incorrect digit, closing ...\n";
      } 
    
    }

  }

  return id; 
 
}

/*
  Prints options menu to user's console.
*/

/**
 * @details
 * Tree and id are updated by menu_helper during interactive binary tree session.
 */

void menu() {  
  
  Tree<int> tree;
  
  int id {};
  
  menu_helper<int>(id, tree);  // value member in nodes are integer type  

}

