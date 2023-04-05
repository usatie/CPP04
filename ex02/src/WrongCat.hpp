#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat& w);
  WrongCat& operator=(const WrongCat& w);
  ~WrongCat();
  void makeSound() const;

 protected:
 private:
};

#endif
