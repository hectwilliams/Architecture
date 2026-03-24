#ifndef PANCAKE_SORT_H
#define PANCAKE_SORT_H

#include <fstream> 
#include <iostream>
#include <vector> 
#include <thread>
#include <chrono>
#include <string>
#include <limits>

/**
 * @brief Prints stack of pancakes. 
 *
 * @param cakes Container of integers 
*/
void print (std::vector<int>&cakes);


/**
 * @brief Enter pancakes using interactive prompt 
 * 
 * @param cakes Container of integers (represents pancakes)
 * 
*/
void get_cakes_user(std::vector<int>&cakes);

/**
 * @brief Clears terminal and prompts user to enter method to load pancakes 
 *
*/
void reset_terminal();


/**i
 * @brief User selects menu option.
 * Option 1) User enters pancake sizes(integers) per repeated request (-1 shuts down interactive method)
 * Option 2) View stack of pancakes
 * Option 3) Sort pancakes 
 * Option 0) Stop program  
 *
 * @param cakes Container of integers (ie pancakes)
*/
void load_cakes(std::vector<int>& cakes);


/**
 * @brief Top level module that creates container(pan-skillet), loads pankcakes and sorts.
 *
*/
void cook_pancakes();


/**
 * @brief Sorts tower of pancakes(integers) using pancake sort
 * A container of 100 elements is initialized to store collection of pancake radi.
 * Function load_cakes is modifies cakes container and once sorted the values are printed to stdout.
 *
*/
void sort(std::vector<int>& cakes);


#endif 
