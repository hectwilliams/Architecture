#ifndef WRITE_H
#define WRITE_H

#define NUMBER_OF_LINES 100
/*
  function:
    file_buffer 

  input:

    stream - rd/io object 

    s - string to be put into stream buffer 

  remarks:

    function communicates to stream's internal buffer to  write to endpoint (i.e. file)
*/
void file_buffer(const std::ifstream &stream, const std::string &s);

#endif 