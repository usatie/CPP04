#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class MateriaDisposeList {
 public:
  MateriaDisposeList();
  MateriaDisposeList(AMateria* m, MateriaDisposeList* next);
  MateriaDisposeList(const MateriaDisposeList& m);
  MateriaDisposeList& operator=(const MateriaDisposeList& m);
  ~MateriaDisposeList();

 private:
  AMateria* _materia;
  MateriaDisposeList* _next;
};

class Character : public ICharacter {
 public:
  Character();
  explicit Character(std::string const& name);
  Character(const Character& c);
  Character& operator=(const Character& c);
  ~Character();

  // member function
  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);

 protected:
 private:
  std::string _name;
  AMateria* _materia[4];
  MateriaDisposeList* _disposeList;
};

#endif
