#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& w);
  WrongAnimal& operator=(const WrongAnimal& w);
  virtual ~WrongAnimal();
  void makeSound() const;
  std::string getType() const;

 protected:
  std::string type;
};

#endif
