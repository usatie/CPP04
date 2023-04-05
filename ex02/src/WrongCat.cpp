#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() {
  std::cout << "[ WrongCat Default constructor called ]" << std::endl;
  type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& w) : WrongAnimal(w) {
  std::cout << "[ WrongCat Copy constructor called ]" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& w) {
  std::cout << "[ WrongCat Copy assignment operator called ]" << std::endl;
  if (this == &w) return *this;
  WrongAnimal::operator=(w);
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << "[ WrongCat destructor called ]" << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << "WrongCat: Meow!" << std::endl;
}
