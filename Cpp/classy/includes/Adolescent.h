#include <string> 
#include <Baby.h>

#ifndef ADOLESCENT_H
#define ADOLESCENT_H

class Adolescent : public Baby {

  private:
  
    const static std::string gf_name;

  public :
    
    Adolescent ();

    const static bool is_virgin;
    
    const static bool used_drugs; 
    
    const static bool is_athletic; 

    static bool is_walking;

    void speak();
};

#endif 