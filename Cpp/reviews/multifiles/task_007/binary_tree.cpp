#include "binary_tree.h"
#include <iostream>

/**
 * @details
 * Loop-bsed (non-recursive) implementation used to handle data inserts to binary tree.   
 *
*/

template <typename T>
void insert_(T v, Tree<T>& tree){
  if (tree.root==nullptr) {

    tree.root = get_node_heap<T>(v);

  } else {
    
    Node<T>* node = tree.root;

    /* break when leaf node is added */ 
    while (true)  {
      
       /* break if new entry exist in tree */

      if (node->value == v) {

        ++node->count;
        break;

      } else if (v < node->value) {

        if (node->left == nullptr){
          node->left = get_node_heap<T>(v);
          node = node->left;
          break;
        } 
        else {
          node = node->left;
        }
 
      } else {
        
        if (node->right == nullptr){
          node->right = get_node_heap<T>(v);
          node = node->right;
          break;
        }
        else {
          node = node->right;
        }
 
      }
    }

  }
}

/**
 * @details
 * Definitions of allowed types for insert_ command. A wrapper is used to call a single templated function  
 *
*/
template <>
void insert<int>(int v, Tree<int>& tree) {
  insert_<int>(v, tree);
}

template <>
void insert<double>(double v, Tree<double>& tree) { 
  insert_<double>(v, tree);
}

/**
 * @details
 * Helper function to delete_tree.
 *
 */
template <typename T>
void delete_helper(Node<T>* node){

  if (node->left != nullptr){
    delete_helper<T>( node->left);
    std::cout << node->left->value << " ";
    delete node->left;
  }
  
  if (node->right != nullptr) {
    delete_helper<T>( node->right);
    std::cout << node->right->value << " ";
    delete node->right;
  }

}

/**
 * @details
 * Entry point to binary tree deletion.
 */
template <typename T>
void delete_tree_(Tree<T>& tree){
  
  std::cout << "deleting ...";
  if (tree.root) { 
    delete_helper<T>(tree.root);
    std::cout << tree.root->value << '\n';
    delete tree.root;
  } 
}

template <>
void delete_tree<int>(Tree<int>& tree) {
 delete_tree_<int>(tree);
}


/**
 * @details
 * Implementation does not support heap memory checks/error-handling.    
 */
template <typename T>
Node<T>* get_node_heap(T v) {
  Node<T>* dynamic_node = new Node<T>{nullptr, nullptr, 1, v}; 
  return dynamic_node;
}

/**
 * @details
 * Helper function for print_ function. 
 * 
*/
template <typename T>
void print_helper(Node<T>* node) {

  if (node->left != nullptr) {
    print_helper(node->left);
  } 
  std::cout << node->value << " ";
  
  if (node->right != nullptr) {
    print_helper(node->right);
  }

}

/**
 * @details
 * The implementation uses recursion to traverse binary tree. 
 * 
*/
template <typename T>
void print_(Tree<T>& tree) {
  Node<T>* node = tree.root;
  print_helper<T>(node);
}


/**
 *
 * @brief Wrapper function for print_.
 *
 * @param _tree_ Passed by reference Tree structure
 *
*/
template <>
void print<int>(Tree<int>& tree ) {
  print_<int>(tree);
}

template <>
void print<double>(Tree<double>& tree ) {
  print_<double>(tree);
}


 
