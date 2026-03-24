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
 * @param cakes Vector container of integers 
*/
void print (std::vector<int>&cakes);


/**
 * @brief Enter pancakes using interactive prompt 
 * 
 * @param cakes Vector container of integers (represents pancakes)
 * 
*/
void get_cakes_user(std::vector<int>&cakes);

/**
 * @brief Clears terminal and prompts user to enter method to load pancakes 
 *
*/
void reset_terminal();


/**i
 * @brief User select pankcake loading  method.
 * Two methods exist:
 * 1) Read pancakes.txt file and list pancake sizes
 * 2) User enters pancake sizes(integers) per repeated request (-1 shuts down interactive method)
 * After loading pankcake radi the stack of cakes are printed to stdout
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
