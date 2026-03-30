/*

Puzzle 
Randomized T×T grid of tiles. 15 of the tiles have numbers 1 through 15. One tile is missing with value of 0.
User can only move by swapping the tile with value 0. There exists steps that can produce a sorted square grid with zero tile in rightmost corner. Enjoy :) .

Unsorted (start): 

 15   1   4
  2   5   9  12
  7   8  11  14
 10  13   6   3


Sorted(after succesful game session): 

  1   2   3   4
  5   6   7   8
  9  10  11  12
 13  14  15   


Author: HW

*/

#include "puzzle.h"

template <std::size_t  T>
Grid<T> Puzzle<T>::operator()() const {

  return this->data;

}

template <std::size_t  T>
std::ostream& operator<< (std::ostream & out, const Puzzle<T>& p) {

  for (std::size_t r = 0; r < T; ++r) {
    for (std::size_t  c = 0; c < T; ++c) { 
      out  <<  p()[r * T + c]  << " ";
    }
    out << '\n';
  }
  return out;
}

template <std::size_t  T>
std::ostream& operator<< (std::ostream & out, const Record<T>& record) {
for (std::size_t r = 0; r < T; ++r) {
    for (std::size_t  c = 0; c < T; ++c) {
      out <<  record.grid[r * T + c]  << " ";
    }
    out << '\n';
}
  return out;
}

template <std::size_t T>
void Puzzle<T>::reset() const {

  this->data = TEST_DATA;

}


bool  operator== (const Pos &p1, const Pos &p2 ) {
  
  return p1[0] == p2[0] && p1[1] == p2[1];

}


template <std::size_t T>
bool valid_move(const Record<T>& record, const Pos &dest, Snapshots<T> &observed_state, Record<T> &next_record ) {


  // next move is within grid bounds 

  if (dest[0] < 0 || dest[0] >= T || dest[1] < 0 || dest[1] >= T) { 

    return false;

  } 
 
  // set next record position   

  next_record.pos = dest; 
 
  // copy prev grid 

  next_record.grid = record.grid;  

  // possible move (swap) 
  
  std::swap(next_record.grid[record.pos[0] * T + record.pos[1]], next_record.grid[dest[0] * T + dest[1]] );
  
  auto search_loop
  {
    // binded snapshots argument to capture block
    
    std::find_if(observed_state.begin(), observed_state.end(), [ &record ](const Record<T> prev_record){  
    
      return  ( (prev_record.pos == record.pos) && std::equal( prev_record.grid.begin(), prev_record.grid.end(), record.grid.begin()  )); // test pos and grid snapshots

    }) 

  };

  if (  search_loop == observed_state.end() ){  // end reached so no loop :)
  
 
    return true;

  }

  return false; 
}

template <std::size_t T> 
bool sorted(const Grid<T>&  g) {

  //std::is_sorted()
  return true;
}

template <std::size_t T>
void Puzzle<T>::sort() {

  bool finish{};
  Pos pos;
  
  // find -1 
  pos = Pos{0, 0};
 
  std::string_view m1{"solving ."};

  std::string_view m2{"solving . ."};
  
  std::string_view  m3{"solving . . . "};

  Message msg_node3 = Message{m3, nullptr };
  Message msg_node2 = Message{m2, &msg_node3 };
  Message msg_node1 = Message{m1, &msg_node2  };
  Message const *msg_ptr = &msg_node1; // always pointers to head 
  Message *msg_node =    &msg_node3;

  msg_node3.next = const_cast<Message*>(msg_ptr); // create loop
   
  States<T> list = States<T>{};

  Snapshots<T> observed_state{}; 

  list.push_back( Record<T>{ {0,0}, TEST_DATA  }  ); // implicit conversion 
  
  Record<T>record; 
  
  int count = 0;
  
  int count2 = 0;
  
  while (!list.empty()) {
    
    record = list.back(); // top of stack 
    
    list.pop_back();  // pop goes the weasle 

    if (*(record.grid.end() - 1) == 0) { // iterator 
      
       if (std::is_sorted(record.grid.begin(), record.grid.end()-2)) {
        
        assert(0);
    
        std::cout << record << '\n';
       }

    }

    // up
    list.push_back(Record<T>{});   
    if( ! valid_move(record, Pos{record.pos[0] - 1, record.pos[1]} , observed_state, list.back()) ) 
      list.pop_back(); // remove is move is invalid 
     
 
    // down
    list.push_back(Record<T>{});   
    if( ! valid_move(record, Pos{record.pos[0] +  1, record.pos[1]} , observed_state, list.back()) )  
      list.pop_back(); // remove is move is invalid 

    // right
    list.push_back(Record<T>{});
    if( ! valid_move(record, Pos{record.pos[0] , record.pos[1] + 1 } , observed_state, list.back()))
      list.pop_back(); // remove is move is invalid


    // left 
    list.push_back(Record<T>{});
    if( ! valid_move(record, Pos{record.pos[0] , record.pos[1] - 1} , observed_state, list.back()) )
      list.pop_back(); // remove is move is invalid

    // add record (state) to 
    observed_state.push_back(record); // copy to previous states stack
    
 
    if ((count % 1000) == 0) {
      msg_node = msg_node->next;
      std::cout << "\x1b[2K\r" << std::flush; 
      std::cout << '\r' << msg_node->msg << std::flush ;
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

  }

  ++count; 
  
}

template <std::size_t T> 
void Puzzle<T>::operator()() {

  std::vector<int> numbers(T*T);

  std::iota(numbers.begin(), numbers.end(), 1);
  
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // seeded by tick 

  // 3. Create a Mersenne Twister random number engine
  std::mt19937 rng(seed);

  // 4. Shuffle the vector using std::shuffle and the RNG
  std::shuffle(numbers.begin(), numbers.end(), rng);

  for (int r = 0; r < T; ++r) {
    for(int c = 0; c < T; ++c) {
      data[r*T + c] = numbers[r*T +c];
      if (data[r*T + c] == 0)
        emptyPos[0] =r;
        emptyPos[1] =c;
        
    }
  }

}

std::ostream& operator<< (std::ostream & out, const Pos& m){

  out  << "(" << m[0] << "," << m[1] << ")";
  return out; 

}


template <std::size_t T>
void Puzzle<T>::move(int row_offset, int col_offset) {
  int next_r = this->emptyPos[0] + row_offset;
  int next_c = this->emptyPos[1] + col_offset;

  if ( (next_r >= 0  && next_r < static_cast<int>(T) ) && ( next_c >= 0 && next_c < static_cast<int>(T) ) ) {
    
    std::swap( this->data[this->emptyPos[0] * static_cast<int>(T) + this->emptyPos[1]], this->data[next_r * static_cast<int>(T) + next_c ]  );
    

    this->emptyPos[0] = next_r;
    this->emptyPos[1] = next_c;
    
  }    

}


template <std::size_t T>
void Puzzle<T>::play(){
  std::cout << "Position of marker: "<< emptyPos << "\nSelect Option from list\n1) move up\n2) move right\n3) move down\n4) move left\n5) noop(print grid)\n6) quit\n";
  int select;  

  while (true) {
     
    std::cin >> select; 

    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\x1b[A";
      std::cout << "\rInput error, please try again and select from integer options" << std::flush ;
      std::this_thread::sleep_for(std::chrono::milliseconds(800));
      std::cout << "\x1b[2K\r: " << std::flush;
      continue;
  
    } else {
      
      switch(select) {

      case 1:
        this->move(-1, 0);
        break;
      case 2:
        this->move(0, 1);
        break;
      case 3:
        this->move(1, 0);
        break;
      case 4:
        this->move(0, -1);
        break;
      case 5:
        break;
      case 6:
        return;
      default:
        break;

      }

      std::cout << *this;
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
      for(int i = 0; i < 13; ++i)
        std::cout << "\033[1A\033[2K"; 
      std::cout << "Position of marker: "<< emptyPos << "\nSelect Option from list\n1) move up\n2) move right\n3) move down\n4) move left\n5) noop(print grid)\n6) quit\n";
      std::cout << ':';

      
    }

    if (std::is_sorted(this->data.begin(), this->data.end()-1)) {
 
      assert(0); 
 
    }
  
  }
  
}


int main() {

  Puzzle<4> puzzle{};

  //std::cout << puzzle; 
 
  // puzzle.sort(); // brute force non-optimal algorithm  DO NOT RUN, KEEP THIS COMMENTED  :).

  puzzle.play(); 
 
}

