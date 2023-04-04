#include "WrongDog.hpp"

#include <iostream>

WrongDog::WrongDog() {
  std::cout << "[ WrongDog Default constructor called ]" << std::endl;
  type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog& w) : WrongAnimal(w) {
  std::cout << "[ WrongDog Copy constructor called ]" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& w) {
  std::cout << "[ WrongDog Copy assignment operator called ]" << std::endl;
  if (this == &w) return *this;
  WrongAnimal::operator=(w);
  return *this;
}

WrongDog::~WrongDog() {
  std::cout << "[ WrongDog destructor called ]" << std::endl;
}

void WrongDog::makeSound() const {
  std::cout << "WrongDog: Woof!" << std::endl;
}
