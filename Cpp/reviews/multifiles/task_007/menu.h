#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <limits>
#include "binary_tree.h"

/**
 * @struct Menu_Options
 * @brief Options available to user.  
 *
*/
enum Menu_Options {
  
  Insert = 1,  /**< Insert value into binary tree */
  Print,       /**< Print sorted values in increasing order  */
  Stop         /**< Quits programa deallocates all binary tree resources */

};

/**
 *
 * @brief Create interactive menu on user's console to  create a binary tree. This function serves as the entry point allocating tree and id object on stack while  
 * menu_helper performs interfactive workload.
 *
*/
void menu();

/**
 *
 * @brief Print menu to user's stdout. The following options
 * are available: Insert value to tree, print values in binary tree in-order, quit session and delete all dynamically allocated resources.
 * If user select the Insert Option, they will be prompted to add an integer value.  
 *
 * @param _id_   Option selected by user
 * @param _tree_ Tree object  
*/
template <typename T>
int menu_helper(int& id, Tree<T>& tree);

//template <>
//void insert<int>(int v, Tree<int>& tree){} // explicit define template type 


#endif 
