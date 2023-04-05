#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria() : _type("default") {
#ifdef DEBUG
  std::cout << "[ AMateria Default constructor called ]" << std::endl;
#endif
}

AMateria::AMateria(std::string const& type) : _type(type) {
#ifdef DEBUG
  std::cout << "[ AMateria constructor called ]" << std::endl;
#endif
}

AMateria::AMateria(const AMateria& a) : _type(a._type) {
#ifdef DEBUG
  std::cout << "[ AMateria Copy constructor called ]" << std::endl;
#endif
}

AMateria& AMateria::operator=(const AMateria& a) {
#ifdef DEBUG
  std::cout << "[ AMateria Copy assignment operator called ]" << std::endl;
#endif
  // While assigning a Materia to another, copying the type doesn’t make sense.
  (void)a;
  return *this;
}

AMateria::~AMateria() {
#ifdef DEBUG
  std::cout << "[ AMateria destructor called ]" << std::endl;
#endif
}

std::string const& AMateria::getType() const {
#ifdef DEBUG
  std::cout << "[ AMateria::getType() called ]" << std::endl;
#endif
  return _type;
}

// AMateria can't be instantiated, so this function is not needed
// AMateria* AMateria::clone() const {
//   return new AMateria(*this) ;
// }

// This is not pure virtual, so it can be called on AMateria
void AMateria::use(ICharacter& target) {
  std::cout << "AMateria::use() called on " << target.getName() << std::endl;
}
