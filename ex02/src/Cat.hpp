#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
 public:
  Cat();
  Cat(const Cat& c);
  Cat& operator=(const Cat& c);
  ~Cat();
  void makeSound() const;
  void printIdeas() const;
  void addIdea(const std::string& idea);

 protected:
 private:
  Brain* _brain;
};

#endif
