#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

// To avoid circular dependency, only declare the class
class AMateria;

class IMateriaSource {
 public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif
