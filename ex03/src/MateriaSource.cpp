#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource() : _materia() {
#ifdef DEBUG
  std::cout << "[ MateriaSource Default constructor called ]" << std::endl;
#endif
}

MateriaSource::MateriaSource(const MateriaSource& m) : _materia() {
#ifdef DEBUG
  std::cout << "[ MateriaSource Copy constructor called ]" << std::endl;
#endif
  for (int i = 0; i < 4; i++) {
    if (m._materia[i]) _materia[i] = m._materia[i]->clone();
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& m) {
#ifdef DEBUG
  std::cout << "[ MateriaSource Copy assignment operator called ]" << std::endl;
#endif
  if (this == &m) return *this;
  for (int i = 0; i < 4; i++) {
    if (_materia[i]) delete _materia[i];
    _materia[i] = NULL;
    if (m._materia[i]) _materia[i] = m._materia[i]->clone();
  }
  return *this;
}

MateriaSource::~MateriaSource() {
#ifdef DEBUG
  std::cout << "[ MateriaSource destructor called ]" << std::endl;
#endif
  for (int i = 0; i < 4; i++) {
    if (_materia[i]) delete _materia[i];
  }
}

// member function
void MateriaSource::learnMateria(AMateria* m) {
#ifdef DEBUG
  std::cout << "[ MateriaSource::learnMateria() called ]" << std::endl;
#endif
  for (int i = 0; i < 4; i++) {
    if (_materia[i] == NULL) {
      // From the subject PDF, it looks like clone is unnecessary here
      _materia[i] = m; 
      return;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
#ifdef DEBUG
  std::cout << "[ MateriaSource::createMateria() called ]" << std::endl;
#endif
  for (int i = 0; i < 4; i++) {
    if (_materia[i] && _materia[i]->getType() == type)
      return _materia[i]->clone();
  }
  return NULL;
}
