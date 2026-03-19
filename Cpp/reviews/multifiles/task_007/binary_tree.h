#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstddef> // for std::nullptr_t
#include <iostream>

/**
 * @struct Node
 * @brief Structure to represent binary tree node
 *
 * Node is templated to store different data type. 
 * Each Node structure is a element on the binary tree.
 * 
*/

template <typename T>
struct Node {
  Node<T>* left  {nullptr}; /**< Node address. */
  Node<T>* right {nullptr}; /**< Node address. */
  int count {}; /**< Number of time value was added to tree. */
  T value {}; /**< Value of templated Node. */
};

/**
 * @struct Tree
 * @brief Structure represents binary tree housing Node objects 
 *
*/

template <typename T >
struct Tree {
  Node<T>* root {};  /**< base type  */
};

template <typename T>
struct Tree<T&> {
  Node<T>& root ;  /**< reference type  */
};

template <typename T>
struct Tree<T*> {
  Node<T>* root {nullptr};  /**< pointer type  */
};


/**
 * @brief Allocates heap segment for Node object, and returns to caller. 
 * 
 * @param _v_ The node's value  
 * @return _value_ Node object address
*/
template <typename T>
Node<T>* get_node_heap(T v);

/**
 * 
 * @brief Inserts value into tree.  
 *
 * Two possible outcomes per call: new leaf node is added or a tree node's count is incremented
 * @param _tree_ Passed by reference Tree structure  
 * @param _v_ Node value  
*/
template <typename T> 
void insert_(T v, Tree<T>& tree);  

/**
 *
 * @brief Wrapper function for insert_.  
 *
 * This function defines different types and calls insert_. Varying types are defined iin binary_tree.cpp
 * @param _tree_ Passed by reference Tree structure
 * @param _v_ Node value
*/

template <typename T>
void insert(T v, Tree<T>& tree);

/**
 * 
 * @brief Using recursive algorithm, function traverses binary tree from node address and deletes descendants.         *
 * @param _node_  Node address.
*/
template <typename T> 
void delete_helper(Node<T*>* node);

/**
 * 
 * @brief Deletes all nodes in tree parameter.
 * This deletion of root node occurs in this function.
 *
 * @param _tree_  Binary tree reference.
*/
template <typename T>
void delete_tree_(Tree<T>& tree);

/**
 *
 * @brief Wrapper function for delete_tree_.
 * 
 * @param _tree_ Passed by reference Tree structure 
 *
*/
template <typename T>
void delete_tree(Tree<T>& tree );

/**
 *
 * @brief Traverses binary tree and prints in-order(i.e. ascending order) tree values to stdout.   
 *
 * @param _tree_ Binary tree reference.
*/

template <typename T>
void print_(Tree<T&>& tree);

/**
 *
 * @brief Wrapper function for print_.
 *
 * @param _tree_ Passed by reference Tree structure
 *
*/
template <typename T>
void print(Tree<T>& tree );








#endif
