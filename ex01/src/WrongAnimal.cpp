#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() {
  std::cout << "[ WrongAnimal Default constructor called ]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& w) {
  std::cout << "[ WrongAnimal Copy constructor called ]" << std::endl;
  WrongAnimal::operator=(w);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& w) {
  std::cout << "[ WrongAnimal Copy assignment operator called ]" << std::endl;
  if (this == &w) return *this;
  type = w.type;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "[ WrongAnimal destructor called ]" << std::endl;
}

void WrongAnimal::makeSound() const {
  std::cout << "[ WrongAnimal makeSound() called ]" << std::endl;
}

std::string WrongAnimal::getType() const {
  std::cout << "[ WrongAnimal getType() called ]" << std::endl;
  return type;
}
