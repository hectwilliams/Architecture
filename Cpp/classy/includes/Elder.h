#include <string> 
#include <Adolescent.h>

#ifndef ELDER_H
#define ELDER_H

class Elder : public Adolescent {

  public :
    
    Elder ();

    const static bool has_virtigo;
    
    const static bool has_grandkids; 
    
    const static bool is_dying; 

     void speak();
};

#endif 