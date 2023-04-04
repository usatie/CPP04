#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal() {
  std::cout << "[ Dog Default constructor called ]" << std::endl;
  type = "Dog";
}

Dog::Dog(const Dog& d) : Animal(d) {
  std::cout << "[ Dog Copy constructor called ]" << std::endl;
}

Dog& Dog::operator=(const Dog& d) {
  std::cout << "[ Dog Copy assignment operator called ]" << std::endl;
  if (this == &d) return *this;
  Animal::operator=(d);
  return *this;
}

Dog::~Dog() { std::cout << "[ Dog destructor called ]" << std::endl; }

void Dog::makeSound() const { std::cout << "Dog: Woof!" << std::endl; }
