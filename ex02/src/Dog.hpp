#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
 public:
  Dog();
  Dog(const Dog& d);
  Dog& operator=(const Dog& d);
  ~Dog();
  void makeSound() const;
  void printIdeas() const;
  void addIdea(const std::string& idea);

 protected:
 private:
  Brain* _brain;
};

#endif
