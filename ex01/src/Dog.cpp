#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal(), _brain(new Brain()) {
  std::cout << "[ Dog Default constructor called ]" << std::endl;
  type = "Dog";
}

Dog::Dog(const Dog& d) : Animal(d), _brain(new Brain(*d._brain)) {
  std::cout << "[ Dog Copy constructor called ]" << std::endl;
}

Dog& Dog::operator=(const Dog& d) {
  std::cout << "[ Dog Copy assignment operator called ]" << std::endl;
  if (this != &d) {
    Animal::operator=(d);
    delete _brain;
    _brain = new Brain(*d._brain);
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "[ Dog destructor called ]" << std::endl;
  delete _brain;
}

void Dog::makeSound() const { std::cout << "Dog: Woof!" << std::endl; }

void Dog::printIdeas() const { std::cout << _brain; }

void Dog::addIdea(const std::string& idea) { _brain->addIdea(idea); }
