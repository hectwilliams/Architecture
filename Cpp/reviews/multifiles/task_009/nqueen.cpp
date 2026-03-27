/*
 N Queens 

 This solution is not optimal. Setting N=5 or lower will solutions with low latency. N >5 will take sometime to compute :(.

 Command: nqueen 8 

 Note: A single integer argument  > 1 is required. If no argument is passed the default N = 5 is used;
 
*/

#include "nqueen.h"

void nqueens(const std::size_t& N) {

  Pos<int> pos{};

  Queens exclude_list{};
 
  CellStatus status{};

  for (std::size_t r = 0; r < N; ++r) {
    for (std::size_t c = 0; c < N; ++c) {
      pos[0] = r;
      pos[1] = c;
      Queens queens{}; 
      long long unsigned  safe_cells{}; 
      if (safe_start(N, pos, status )) {
        std::cout << "Queen set: " << "N=" << N <<  '\n';
        nqueens(N, queens, pos,  status);
        std::cout << queens << '\n'; 
        for(const auto& p: queens)
           status[ static_cast<std::size_t>(p[0]) * N + static_cast<std::size_t>(p[1]) ] = true; 
      }
    }
  }
/*
  int i{};
  for (const auto& a: status) { 
    std::cout << i << ": "  << a << '\n';
    ++i;
    if (i == 100) 
      break; 
  }
*/

}

bool safe_start(const std::size_t&  N, const Pos<int>& pos, CellStatus& status) {
  
  int some_occupied_cell_index = static_cast<int>(N) * pos[0] + pos[1] ;

  if (status[ static_cast<std::size_t>(some_occupied_cell_index) ] ) {
    return false;
  }

  return true; 
}

void move(const std::size_t& N,  Queens& q, const Pos<int>& pos, const Cells& path ,const int& offset_x, const int& offset_y, CellStatus & status ) {

  Pos<int> pos_next {pos[0] + offset_y, pos[1] + offset_x};

  Cells prev_path; 

  if (valid_move(q, pos_next , N, path) ) {

    prev_path = path; // copy path

    prev_path.push_back(pos); // add curr position

    nqueens(N, q, pos_next, status, prev_path); 

  }

}

void nqueens(const std::size_t& N,  Queens& q, const Pos<int>& pos,  CellStatus& status, const Cells& path) {

  bool safe_queen_insert{valid_cell(q, pos, status, N)};
  
  if(safe_queen_insert) {

    q.push_back(pos); // copy Pos into stack  

  }
   
  /* up */
  move(N, q,  pos, path,  0, -1, status);

  /* down */
  move(N, q,  pos,  path ,0, 1, status);
 
  /* left */
  move(N, q,  pos,  path, -1, 0, status);

  /* right */
  move(N, q,  pos,  path, 1, 0, status);

}

bool valid_cell(const Queens& queens, Pos<int> pos, CellStatus & status, const std::size_t & N ) {

  for (const auto& qpos: queens) {

    // row test 
    if(pos[0] == qpos[0]) {return false;}
    
    // column test  
    if(pos[1] == qpos[1] ) {return false;}

    // left  diagonal test (/)
    if((pos[0] - pos[1]) == (qpos[0] - qpos[1])) {return false;}

    // right diagonal test (\)
    if ( (pos[0] + pos[1]  )  == (qpos[0] + qpos[1]) ) { return false;}

  }  

  //  long long unsigned r,c, N2;
  //  r = static_cast<std::size_t>(pos[0]);
  //  c = static_cast<std::size_t>(pos[1]);
  //status[ static_cast<std::size_t>(r * N + c) ] = true; 

  //dec2Bin(safe_cell_status);

  return true; 
    
}

bool valid_move(const Queens & queens, const Pos<int>& dest, const std::size_t& N, const Cells& path) {

  if ( dest[0] < 0 || dest[0] >= N || dest[1] <0 || dest[1] >= N ) {
   
    return false;
  
  }

  for (const auto& prev_cell: path) {
  
    if (prev_cell[0] == dest[0] && prev_cell[1] == dest[1]) {

      return false;
    } 
  
  }
 

  return true; 
}


std::ostream& operator<<( std::ostream& o,  const Pos<int> pos) { 

  o << pos[0] << "," << pos[1];

  return o;

}

std::ostream& operator<<( std::ostream& o, Queens queens) {
 
   for (auto & q_pos: queens) {

    o << q_pos << " ";

  }

  o << "\n";

  return o;

}

void dec2Bin( long long unsigned value) {
  std::string s;  

  std::cout << value << ": ";

  while (value != 0) {
  
    s = (static_cast<long long unsigned>((value %  static_cast<long long unsigned>(2)) >  0) == 1 ? "1" : "0" ) + s ; // append in most sig direction
   
    value /=2;  
       
  }

  std::cout << s << '\n';

}


int main(int argc, char *argv[]) {
  
  if (argc == 1) 
    std::cout << "NQUEEN Using Default N=5\n";
    nqueens(5);
  else if (argc == 2) {
    try {
      int N = std::stoi(argv[1]);
      if (N < 2 ) {
        throw std::invalid_argument("N too small. N must be > 1");
      }
      nqueens(N);
    } catch(const std::invalid_argument&  ex) {
      std::cerr << "Invalid argument: " << ex.what() << std::endl;
    } 
  } else {
    throw std::invalid_argument("Nqueens accepts zero or 1 arguments.");
  }   
}

