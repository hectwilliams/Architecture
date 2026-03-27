#ifndef NQUEEN_H
#define NQUEEN_H

#include <iostream> 
#include <stdexcept>
#include <array>
#include <vector>
#include <cmath> 
#include <array>
#include <cassert>
#include <bitset>
#include <string>

template <typename T>
using Pos = std::array<T,2>; 

using Queens = std::vector<Pos<int>>; // list of 2 element arrays 

using Cells = Queens; 

using Grid = std::vector< std::vector<bool> >;

using CellStatus = std::array<bool, 625>; 

std::ostream& operator<<( std::ostream& o, const Pos<int> pos);

std::ostream& operator<<( std::ostream& o, Queens queens);

/**
 * @brief Solves N queens problem; calle returns number of unique grid objects with queens not in violation 
 *
 * @param N Dimensions of both row and col
*/
void nqueens(const std::size_t&  N);

/**
 * @brief Solves N queens problem. Calle uses recursion to traverse different possible states with valid queens on board  
 *
 * @param N Dimensions of both row and col.
 * @param q list of queens positions (dynamic).
 * @param pos 2D  position on board.
 * @param status Array of boolean objects where each index represents cell on NxN board. A true index represents a queen was placed in a prior or current solver rountine.
 * @param path Container of row,col positions. The position objects are prior locations the solver walked.
*/
void nqueens(const std::size_t&  N, Queens & q, const Pos<int>& pos, CellStatus  & status, const Cells& path = Cells{0} );

/**
 * @brief Determines if queen can be fixed at current position 
 *
 * @param queens List of queen positions.
 * @param pos 2D position on board.
 * @param status Array of boolean objects. Each array index represents a cell location on NxN board.
 * @param N Dimensions of both row and col.  
*/
bool valid_cell(const Queens& queens, Pos<int> pos, CellStatus & status, const std::size_t& N);

/**
 * @brief Determines if dest is a valid move on board
 *
 * @param queens List of queen positions. 
 * @param dest Destination of potential move. 
 * @param N Dimensions of both row and col.
 * @param path Previous locations observed by solver. 
*/
bool valid_move(const Queens& queens, const Pos<int>& dest, const std::size_t& N, const Cells& path);


/**
 * @brief Moves along representative board using offset_y and offset_x parameters to control up,down,right,or left traversal.
 *
 * @param N Dimensions of both row and col.
 * @param q List of queen positions.
 * @param pos 2D position on board.
 * @param path Previous locations observed by solver.
 * @param offset_x Offset to current col location.
 * @param offset_y Offset to current row location.
 * @param status Array of boolean objects.
*/
void move(const std::size_t& N, const Queens& q, const Pos<int>& pos, const Cells& path,const int& offset_x, const int& offset_y, CellStatus& status);

/**
 * @brief Determines if it's safe to start solver at cell position 
 *
 * @param N Dimensions of both row an col.
 * @param pos 2D position on board.
 * @param status Array of boolean objects.
*/
bool safe_start(const std::size_t &N, const Pos<int>& pos, CellStatus  & status);

/**
 * @brief Prints value into binary format
 *
 * @param value Unsigned number to be represented in binary.
*/
void dec2Bin( long long unsigned  value);
#endif 
