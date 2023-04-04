#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("") {
  std::cout << "[ Animal Default constructor called ]" << std::endl;
}

Animal::Animal(const Animal& a) {
  std::cout << "[ Animal Copy constructor called ]" << std::endl;
  Animal::operator=(a);
}

Animal& Animal::operator=(const Animal& a) {
  std::cout << "[ Animal Copy assignment operator called ]" << std::endl;
  if (this == &a) return *this;
  type = a.type;
  return *this;
}

Animal::~Animal() { std::cout << "[ Animal destructor called ]" << std::endl; }

void Animal::makeSound() const {
  std::cout << "[ Animal makeSound() called ]" << std::endl;
}

std::string Animal::getType() const {
  std::cout << "[ Animal getType() called ]" << std::endl;
  return type;
}
