#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {
#ifdef DEBUG
  std::cout << "[ Ice Default constructor called ]" << std::endl;
#endif
}

Ice::Ice(const Ice& i) : AMateria(i) {
#ifdef DEBUG
  std::cout << "[ Ice Copy constructor called ]" << std::endl;
#endif
}

Ice& Ice::operator=(const Ice& i) {
#ifdef DEBUG
  std::cout << "[ Ice Copy assignment operator called ]" << std::endl;
#endif
  // While assigning a Materia to another, copying the type doesn’t make sense.
  (void)i;
  return *this;
}

Ice::~Ice() {
#ifdef DEBUG
  std::cout << "[ Ice destructor called ]" << std::endl;
#endif
}

// member function
AMateria* Ice::clone() const {
#ifdef DEBUG
  std::cout << "[ Ice::clone() called ]" << std::endl;
#endif
  // Since Ice doesn’t have any member variables, it doesn’t need to copy them.
  // return new Ice(*this) ;
  return new Ice();
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
