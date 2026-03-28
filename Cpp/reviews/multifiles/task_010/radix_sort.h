#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <iostream>
#include <array>
#include <functional> 
#include <cassert> 

/**
 * @brief Structure contains integer and ptr to next Node.
 * The structure is used to create linked list within rstorage 
*/
struct Node {

  /**
   * @brief Integer value 
  */
  int value{};

 /**
  *  @brief Pointer to Node object 
 */
  Node* next{nullptr};

};

// Test Data
using Array7 = std::array<int, 7>;
constexpr Array7 TEST_INTEGERS {329, 457, 657, 839, 436, 720, 355}; 

// Storage
using ArrLL = std::array<Node*, 10>;

/*
 * @brief Determines if sort algorithm is done by comparing size of list at ArrLL[0] and the total number of values in evaluation array. 
 *
 * @param head Pointer to LList.
 * @param N Number of elements in evaluation array.
 * @returns Boolean indicating to caller whether to continue or stop algorithm. 
*/
bool sort_done_cb( const Node* node, int N);

/**
 * @brief Radix sort 
 * 
 * @param arr Array of integers 
 * @returns Sorted Array of integers 
 *
*/
Array7 radix_sort(Array7 arr, const std::function<bool(const Node*, int)>& callback );

/**
 * @brief Clear array of linked list  
 *
 * @param storage Array of linked lisk 
*/
void clear_arrll(ArrLL& storage);

/**
 * @brief Add node to linked list 
 *
 * @param sel Array of linked list 
 * @param value Value to load into new node 
 * @param digit_index Index of ArrLL
*/
void add_to_storage(ArrLL& sel, int value, int digit_index);

#endif
