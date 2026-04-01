
#include "thelot.h"

Lot::Lot()
  :area{40} 
{
  //this->area = 40; // sq-ft 
}

int Lot::getArea(){
  return this->area; 
}

 void Lot::setArea(int a) {

  std::cout << " Lot ownwers do not want to expand\n";
  
}


Gym::Gym(){
  this->owner = "Unknown";
  this->numEquipment = 21;
}

Gym::Gym(std::string name)
  :owner{name}
{}

std::string Gym::getOwnerName(){
 
  return this->owner; 

}


 void Gym::setArea(int a) {
  auto* base_ptr {static_cast<Lot*>(this)};

  if ( base_ptr->getArea() >= a ) {
    std::cout << "Area must be greater than, come back with larger gym specs " << a << '\n';
    return;
  }
  
  this->area = a;

  std::cout << "expanded size of gym to " << a << '\n';

}

void Gym::addMember() {

  ++this->numMembers;
}
 

void Gym::removeMember() {

  --(this->numMembers);
}


bool Gym::demolition() {

  return (this->numMembers != 0);

}


bool random_bool() {
  std::random_device rd;
  std::mt19937 gen(rd()); 
  std::bernoulli_distribution d;
  bool random_bit = d(gen);
  return random_bit;  

} 
