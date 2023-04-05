#include "Character.hpp"

#include <iostream>

// MateriaDisposeList

MateriaDisposeList::MateriaDisposeList() : _materia(NULL), _next(NULL) {
#ifdef DEBUG
  std::cout << "[ MateriaDisposeList Default constructor called ]" << std::endl;
#endif
}

MateriaDisposeList::MateriaDisposeList(AMateria* m, MateriaDisposeList* next)
    : _materia(m), _next(next) {
#ifdef DEBUG
  std::cout << "[ MateriaDisposeList constructor called ]" << std::endl;
#endif
}

MateriaDisposeList::MateriaDisposeList(const MateriaDisposeList& m)
    : _materia(m._materia), _next(NULL) {
#ifdef DEBUG
  std::cout << "[ MateriaDisposeList Copy constructor called ]" << std::endl;
#endif
  if (m._next) _next = new MateriaDisposeList(*m._next);
}

MateriaDisposeList& MateriaDisposeList::operator=(const MateriaDisposeList& m) {
#ifdef DEBUG
  std::cout << "[ MateriaDisposeList Copy assignment operator called ]"
            << std::endl;
#endif
  if (this == &m) return *this;
  if (_next) delete _next;
  _next = NULL;
  if (_materia) delete _materia;
  _materia = m._materia;
  if (m._next) _next = new MateriaDisposeList(*m._next);
  return *this;
}

MateriaDisposeList::~MateriaDisposeList() {
#ifdef DEBUG
  std::cout << "[ MateriaDisposeList destructor called ]" << std::endl;
#endif
  if (_next) delete _next;
  if (_materia) delete _materia;
}

// Character
Character::Character() : _name("default"), _materia(), _disposeList() {
#ifdef DEBUG
  std::cout << "[ Character Default constructor called ]" << std::endl;
#endif
}

Character::Character(std::string const& name)
    : _name(name), _materia(), _disposeList() {
#ifdef DEBUG
  std::cout << "[ Character constructor called ]" << std::endl;
#endif
}

Character::Character(const Character& c)
    : _name(c._name), _materia(), _disposeList() {
#ifdef DEBUG
  std::cout << "[ Character Copy constructor called ]" << std::endl;
#endif
  for (int i = 0; i < 4; i++) {
    if (c._materia[i]) _materia[i] = c._materia[i]->clone();
  }
  // Dispose list should be empty
}

Character& Character::operator=(const Character& c) {
#ifdef DEBUG
  std::cout << "[ Character Copy assignment operator called ]" << std::endl;
#endif
  if (this == &c) return *this;
  _name = c._name;
  for (int i = 0; i < 4; i++) {
    if (_materia[i]) delete _materia[i];
    _materia[i] = NULL;
    if (c._materia[i]) _materia[i] = c._materia[i]->clone();
  }
  delete _disposeList;
  _disposeList = NULL;
  return *this;
}

Character::~Character() {
#ifdef DEBUG
  std::cout << "[ Character destructor called ]" << std::endl;
#endif
  for (int i = 0; i < 4; i++) {
    if (_materia[i]) delete _materia[i];
  }
  delete _disposeList;
}

// member function
std::string const& Character::getName() const {
#ifdef DEBUG
  std::cout << "[ Character::getName() called ]" << std::endl;
#endif
  return _name;
}

void Character::equip(AMateria* m) {
#ifdef DEBUG
  std::cout << "[ Character::equip() called ]" << std::endl;
#endif
  for (int i = 0; i < 4; i++) {
    if (_materia[i] == NULL) {
      _materia[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
#ifdef DEBUG
  std::cout << "[ Character::unequip() called ]" << std::endl;
#endif
  if (idx >= 0 && idx < 4) {
    // Text from Subject PDF:
    //
    // The unequip() member function must NOT delete the Materia!
    //
    // Handle the Materias your character left on the floor as you like.
    // Save the addresses before calling unequip(), or anything else, but
    // don’t forget that you have to avoid memory leaks.
    if (_materia[idx]) {
      _disposeList = new MateriaDisposeList(_materia[idx], _disposeList);
      _materia[idx] = NULL;
    }
  }
}

void Character::use(int idx, ICharacter& target) {
#ifdef DEBUG
  std::cout << "[ Character::use() called ]" << std::endl;
#endif
  if (idx >= 0 && idx < 4) {
    if (_materia[idx]) _materia[idx]->use(target);
  }
}
