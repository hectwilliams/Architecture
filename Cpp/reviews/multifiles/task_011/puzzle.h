#ifndef PUZZLE_H
#define PUZZLE_H 

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert> 
#include <chrono>
#include <thread>
#include <random>
#include <limits>

struct Message {
  std::string_view msg;
  Message *next;
};

using Pos = std::array<int,2>;

template <std::size_t T>
using Grid = std::array<int,  T*T>;

template <std::size_t T>
struct Record {
  Pos pos;
  Grid<T> grid;
};

Grid<4> TEST_DATA = { {0, 15, 1 , 4, 2, 5, 9, 12 , 7, 8, 11, 14, 10, 13, 6, 3} }; 

using Tuple2 = std::pair<Pos, Grid<4>>;

template <std::size_t T>
using States = std::vector<Record<T>>; 

template <std::size_t T>
using Snapshots = std::vector<Record<T>>;

template <std::size_t  T>
class Puzzle {

private:
  Pos emptyPos{0, 0};
  Grid<T> data;

public:

  Puzzle<T> () {
   
    data = TEST_DATA;    
 
  }
  /*
   * @brief Overload parenthesis returning the Grid member. 
   * @returns Grid object 
  */
  Grid<T> operator()() const; 

  /**
   * @brief Sort Grid of tiles 
   *
   * 
  */
  void sort();

  /**
   * @brief Reset puzzle. TEST_DATA is loaded in data. 
   *
   * 
  */
  void clear();

  /**
   * @brief Set data member to TEST_DATA
   *
  */
  void reset() const;  

  /**
   * @brief Play Game where user makes adjacent moves from marker cell (value = -1).
   *
   * Program will prompt user at each step. Options allow robotic movements and the ability to quit game.
  */
  void play();

 /**
   * @brief Load board with new shuffled tiles 
   *
  */
  void operator()();

 /**
  * Move marker tile up
  *
 */
  void move(int row_offset, int col_offset);

};

/*
 * @brief overload operator<<, to print user-defined class
 *
 * @param out ostream object
 * @param p Puzzle object
*/
template <std::size_t T>
std::ostream& operator<< (std::ostream & out, const Puzzle<T>& p);

/*
 * @brief overload operator<<, to print user-defined class
 *
 * @param out ostream object
 * @param record Record object
*/
template <std::size_t T>
std::ostream& operator<< (std::ostream & out, const Record<T>  &record);

/**
 * @brief Overload Pos object 
 *
 * @param out ostream object
 * @param m Record object
*/
template <std::size_t T>
std::ostream& operator<< (std::ostream & out, const Pos& m);



/**
 * @brief Compare Pos objects 
 *
 * @param p1 Pos Object 
 * @param p2 Pos Object 
*/
bool operator== (const Pos &p1, const Pos &p2 );

/*
 * @brief Determine if swap/jump is safe and move is within border limits   
 *
 * @param record Record containing current position of blank tile on grid and grid object 
 * @param dest Position after jumpa
 * @param snapshots Previously observed grids (snapshots) 
 * @returns Boolean 
*/
template <std::size_t T>
bool valid_move(const Record<T>& record, const Pos &dest, Snapshots<T> &snapshots, Record<T>& next_record);

/*
 * @brief Determine is solver has looped back to a previous state  
 *
 * @param curr Current snapshot
 * @param next  Next snapshot
 * @returns Boolean
*/
template <std::size_t T>
bool valid_tile(const Record<T> &curr, Snapshots<T> &snapshots );

/*
 * @brief Determine if Grid is sorted
 *
*/
template <std::size_t T>
bool sorted(const Grid<T>&  g);


/**
 * @brief Play Game where user makes adjacent moves from marker cell (value = -1).
 *
 *Program will prompt user at each step. Options allow robotic movements and the ability to quit game.
*/

 


#endif  
