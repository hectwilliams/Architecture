#include "thelot.h" 

int main() {

  Gym gym;

  gym.setArea(200);  

  // randomly add member 
  if(random_bool())
    gym.addMember();

  // destroy gym if it's safe
  if(gym.demolition())
    std::cout << "gym has been removed\n";
}

