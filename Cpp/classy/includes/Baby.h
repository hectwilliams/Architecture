#include <string> 

#ifndef BABY_H
#define BABY_H

class Baby {
  
  public:
    
    Baby();

    const static std::string birthday;

    const static std::string eye_color;

    const static std::string hair_color;
    
    const static std::string color;

    const static std::string height;
    
    static bool is_walking;

    void speak ();

};

#endif 

