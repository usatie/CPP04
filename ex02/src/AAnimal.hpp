#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class AAnimal {
 public:
  AAnimal();
  AAnimal(const AAnimal& a);
  AAnimal& operator=(const AAnimal& a);
  virtual ~AAnimal();
  virtual void makeSound() const = 0;
  std::string getType() const;

 protected:
  std::string type;
};


#endif
