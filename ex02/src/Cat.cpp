#include "Cat.hpp"

#include <iostream>

Cat::Cat() : AAnimal(), _brain(new Brain()) {
  std::cout << "[ Cat Default constructor called ]" << std::endl;
  type = "Cat";
}

Cat::Cat(const Cat& c) : AAnimal(c), _brain(new Brain(*c._brain)) {
  std::cout << "[ Cat Copy constructor called ]" << std::endl;
}

Cat& Cat::operator=(const Cat& c) {
  std::cout << "[ Cat Copy assignment operator called ]" << std::endl;
  if (this != &c) {
    AAnimal::operator=(c);
    delete _brain;
    _brain = new Brain(*c._brain);
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "[ Cat destructor called ]" << std::endl;
  delete _brain;
}

void Cat::makeSound() const { std::cout << "Cat: Meow!" << std::endl; }

void Cat::printIdeas() const { std::cout << _brain; }

void Cat::addIdea(const std::string& idea) { _brain->addIdea(idea); }
