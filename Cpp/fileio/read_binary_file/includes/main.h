#include <fstream>

using namespace std;

#ifndef READ_BINARY_H
#define READ_BINARY_H

#define BYTES_1600 1600 
#define UPDATE_DUMMY_FILE 1
#define SLIDING_WINDOW_BUFFER_SIZE 8
#define CHECKID "DEADBEEF" // 44 45 41 44 42 45 45 46 0A

/*
  function:

    gen_file 

  input:

    stream - input stream operating on file 

    filename - basename of file 
*/
void gen_file( const std::ifstream &stream,  const std::string filename);

/*
  function:

    write_1600_random_bytes 

  input:

    stream - input stream operating on file 

*/
void write_1600_random_bytes( const std::ifstream &stream);

/*
  function:

    find_deadbeef 

  input:

    stream - input stream operating on file 

*/
void find_deadbeef(const std::ifstream &stream);

#endif 
