#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
 public:
  WrongDog();
  WrongDog(const WrongDog& w);
  WrongDog& operator=(const WrongDog& w);
  ~WrongDog();
  void makeSound() const;

 protected:
 private:
};

#endif
