#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  Ice();
  Ice(const Ice& i);
  Ice& operator=(const Ice& i);
  ~Ice();
  // member function
  AMateria* clone() const;
  void use(ICharacter& target);

 protected:
 private:
};

#endif
