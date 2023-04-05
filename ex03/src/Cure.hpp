#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
 public:
  Cure();
  Cure(const Cure& c);
  Cure& operator=(const Cure& c);
  ~Cure();
  // member function
  AMateria* clone() const;
  void use(ICharacter& target);
};

#endif
