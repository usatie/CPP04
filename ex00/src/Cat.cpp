#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal() {
  std::cout << "[ Cat Default constructor called ]" << std::endl;
  type = "Cat";
}

Cat::Cat(const Cat& c) : Animal(c) {
  std::cout << "[ Cat Copy constructor called ]" << std::endl;
}

Cat& Cat::operator=(const Cat& c) {
  std::cout << "[ Cat Copy assignment operator called ]" << std::endl;
  if (this == &c) return *this;
  Animal::operator=(c);
  return *this;
}

Cat::~Cat() { std::cout << "[ Cat destructor called ]" << std::endl; }

void Cat::makeSound() const { std::cout << "Cat: Meow!" << std::endl; }
