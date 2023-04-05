#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource();
  MateriaSource(const MateriaSource& m);
  MateriaSource& operator=(const MateriaSource& m);
  ~MateriaSource();

  // member function
  virtual void learnMateria(AMateria* m);
  virtual AMateria* createMateria(std::string const& type);

 protected:
 private:
  AMateria* _materia[4];
};

#endif
