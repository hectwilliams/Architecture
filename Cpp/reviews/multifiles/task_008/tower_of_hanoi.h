#ifndef TOWER_OF_HANOI_H
#define TOWER_OF_HANOI_H

#include <string>
#include <iostream>
#include <cassert> 

/**
 *  @brief Tower Of Hanoi class
 *
*/
struct TowerOfHanoi {
  std::string tower1 {"abc"};  /**< Represents Tower 1, initialized with a, b ,c disks  */
  std::string tower2 {};       /**< Represents Tower 2 */
  std::string tower3 {};       /**< Represemts Tower 3 */
  std::string states {};       /**< Scratchpad keeping history of past states */
};

/** 
 * @brief Tower Of Hanoi solver. 
 * 
 * The algorithm end once it finds set tower3 to "abc". 
 * The characters a,b,c represent disks ordered by the following  : a < b < c. 
 * The order must always be maintained for each tower. 
 * Two alias versions of function exist. The void parameter function is the entry level module for solving TowerOfHanoi
 * while single parameter referenced version is responsible to complex computation. 
*/
void toh();

/** 
 *  @brief Tower Of Hanoi solver 
 *
 *  @param t TowerOfHanoi struct
 *
*/
void toh(const TowerOfHanoi& t);


/**
 * @brief Check if character can be added to dest.
 *
 *
 * @param c Character representing disk  
 * @param dest String object representing tower with or without disks 
 * @return Boolean informing caller if a disk added to a tower is safe.  
*/
bool valid_disk_move(const char& c, const  std::string&  dest);

/**
 * @brief Check if state has occurred within TowerOfHanoi object
 *
 * This informs the caller whether to continue solving from this state.
 *@ param TowerOfHanoi object
 *@ return Boolean informning the caller whether or not we have returned to a previous state.  
*/
bool valid_state(const TowerOfHanoi& t);


/**
 * @brief Count number of newline characters in scratchpad
 *
 * @param s Scratchpad 
 * @return number of lines in scratchpad
*/
int nlines(const std::string& s);

#endif

