#include "Brain.hpp"

#include <iostream>

Brain::Brain() : _ideas(), _i(0) {
  std::cout << "[ Brain Default constructor called ]" << std::endl;
}

Brain::Brain(const Brain& b) {
  std::cout << "[ Brain Copy constructor called ]" << std::endl;
  operator=(b);
}

Brain& Brain::operator=(const Brain& b) {
  std::cout << "[ Brain Copy assignment operator called ]" << std::endl;
  if (this != &b) {
    for (int i = 0; i < NUM_OF_IDEAS; i++) {
      this->_ideas[i] = b._ideas[i];
    }
    _i = b._i;
  }
  return *this;
}

Brain::~Brain() { std::cout << "[ Brain destructor called ]" << std::endl; }

std::string Brain::getIdea(int i) const {
  // Index out of range
  if (i < 0 || i >= NUM_OF_IDEAS) {
    return "";
  }
  return this->_ideas[i];
}

void Brain::addIdea(const std::string& idea) {
  // Index out of range
  if (_i < 0 || _i >= NUM_OF_IDEAS) {
    return;
  }
  this->_ideas[_i] = idea;
  _i++;
}

std::ostream& operator<<(std::ostream& os, const Brain& b) {
  os << "[Inside of the brain]" << std::endl;
  for (int i = 0; i < NUM_OF_IDEAS; i++) {
    if (b.getIdea(i) != "")
      os << "Idea " << i << ": " << b.getIdea(i) << std::endl;
  }
  os << "[End of the brain]" << std::endl;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Brain* b) {
  os << *b;
  return os;
}
