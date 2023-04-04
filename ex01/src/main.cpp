#include <iomanip>
#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

#define RESET "\033[m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BOLD "\033[1m"

// print title in green color surrounded by '='
void printTitle(std::string const& title) {
  // set color to green
  std::cout << GREEN << BOLD;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // print title at the center
  std::cout << std::setfill(' ') << std::setw(40 - title.length() / 2) << ""
            << title << std::endl;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // reset color
  std::cout << RESET << std::setfill(' ') << std::setw(0);
}

void test_animal() {
  // Test Orthodox Canonical Form
  {
    printTitle("Test Orthodox Canonical Form");
    Animal a;
    Animal b(a);
    Animal c;
    c = a;
  }
  // Test getType and makeSound
  {
    printTitle("Test getType and makeSound");
    Animal a;
    std::cout << a.getType() << " " << std::endl;
    a.makeSound();
  }
}

void test_dog() {
  // Test Orthodox Canonical Form
  {
    printTitle("Test Orthodox Canonical Form");
    Dog a;
    Dog b(a);
    Dog c;
    c = a;
  }
  // Test getType and makeSound
  {
    printTitle("Test getType and makeSound");
    Dog a;
    std::cout << a.getType() << " " << std::endl;
    a.makeSound();
  }
}

void test_cat() {
  // Test Orthodox Canonical Form
  {
    printTitle("Test Orthodox Canonical Form");
    Cat a;
    Cat b(a);
    Cat c;
    c = a;
  }
  // Test getType and makeSound
  {
    printTitle("Test getType and makeSound");
    Cat a;
    std::cout << a.getType() << " " << std::endl;
    a.makeSound();
  }
}

void test_from_subject() {
  printTitle("Test from subject");
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  delete j;  // should not create a leak
  delete i;
  delete meta;
}

void test_wrong_animal() {
  printTitle("Test WrongAnimal");
  const WrongAnimal* meta = new WrongAnimal();
  const WrongAnimal* j = new WrongDog();
  const WrongAnimal* i = new WrongCat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the wrong animal sound!
  j->makeSound();
  meta->makeSound();
  delete j;  // should not create a leak
  delete i;
  delete meta;
}

// Test Array of Animals
void test_array_of_animals() {
  printTitle("Test array of animals");
  Animal* animals[10];
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0)
      animals[i] = new Cat();
    else
      animals[i] = new Dog();
  }
  for (int i = 0; i < 10; i++) {
    delete animals[i];
  }
}

// Test no memory leak
void test_memory_leak() {
  printTitle("Test no memory leak");
  Cat a;
  std::cout << "Copy brain from a to b" << std::endl;
  { Cat b(a); }
  std::cout << "After b is destroyed" << std::endl;
}

// Test deep Copy
void test_deep_copy() {
  printTitle("Test deep copy");
  Cat a;
  a.addIdea("Idea of a 1");
  a.addIdea("Idea of a 2");
  a.addIdea("Idea of a 3");
  a.addIdea("Idea of a 4");
  a.addIdea("Idea of a 5");
  a.printIdeas();
  std::cout << "Copy brain from a to b" << std::endl;
  {
    Cat b(a);
    b.printIdeas();
    b.addIdea("Idea of b 1");
    b.addIdea("Idea of b 2");
    b.addIdea("Idea of b 3");
    b.addIdea("Idea of b 4");
    b.addIdea("Idea of b 5");
    b.printIdeas();
  }
  std::cout << "After b is destroyed" << std::endl;
  a.printIdeas();
}

int main(void) {
  test_animal();
  test_dog();
  test_cat();
  test_from_subject();
  test_wrong_animal();
  test_array_of_animals();
  test_memory_leak();
  test_deep_copy();
}
