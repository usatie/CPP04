#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class AMateria {
 public:
  AMateria();
  explicit AMateria(std::string const& type);
  AMateria(const AMateria& a);
  AMateria& operator=(const AMateria& a);
  virtual ~AMateria();

  std::string const& getType() const;  // Returns the materia type
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

 protected:
  const std::string _type;

 private:
};

#endif
