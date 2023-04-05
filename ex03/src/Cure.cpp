#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure") {
#ifdef DEBUG
  std::cout << "[ Cure Default constructor called ]" << std::endl;
#endif
}

Cure::Cure(const Cure& c) : AMateria(c) {
#ifdef DEBUG
  std::cout << "[ Cure Copy constructor called ]" << std::endl;
#endif
}

Cure& Cure::operator=(const Cure& c) {
#ifdef DEBUG
  std::cout << "[ Cure Copy assignment operator called ]" << std::endl;
#endif
  // While assigning a Materia to another, copying the type doesn’t make sense.
  (void)c;
  return *this;
}

Cure::~Cure() {
#ifdef DEBUG
  std::cout << "[ Cure destructor called ]" << std::endl;
#endif
}

// member function
AMateria* Cure::clone() const {
#ifdef DEBUG
  std::cout << "[ Cure::clone() called ]" << std::endl;
#endif
  // Since Cure doesn’t have any member variables, it doesn’t need to copy them.
  // return new Cure(*this) ;
  return new Cure();
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
