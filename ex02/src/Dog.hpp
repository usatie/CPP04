#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal {
 public:
  Dog();
  Dog(const Dog& d);
  Dog& operator=(const Dog& d);
  ~Dog();
  void makeSound() const;

 protected:
 private:
};

#endif
