#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("") {
  std::cout << "[ AAnimal Default constructor called ]" << std::endl;
}

AAnimal::AAnimal(const AAnimal& a) {
  std::cout << "[ AAnimal Copy constructor called ]" << std::endl;
  AAnimal::operator=(a);
}

AAnimal& AAnimal::operator=(const AAnimal& a) {
  std::cout << "[ AAnimal Copy assignment operator called ]" << std::endl;
  if (this == &a) return *this;
  type = a.type;
  return *this;
}

AAnimal::~AAnimal() { std::cout << "[ AAnimal destructor called ]" << std::endl; }

// This is a definition of the pure virtual function.
// This can be called from the derived class via AAnimal::makeSound()
void AAnimal::makeSound() const {
  std::cout << "[ AAnimal makeSound() called ]" << std::endl;
}

std::string AAnimal::getType() const {
  std::cout << "[ AAnimal getType() called ]" << std::endl;
  return type;
}
