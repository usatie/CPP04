#include <iostream>
#include <iomanip>
#include "Animal.hpp"

#define RESET "\033[m"
#define GREEN "\e[0;32m"
#define RED "\e[0;31m"
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

void test_animal()
{
  // Test Orthodox Canonical Form
  {
    printTitle("Test Orthodox Canonical Form") ;
    Animal a ;
    Animal b(a) ;
    Animal c ;
    c = a ;
  }
  // Test getType and makeSound
  {
    printTitle("Test getType and makeSound") ;
    Animal a ;
    std::cout << a.getType() << " " << std::endl;
    a.makeSound();
  }
}

void test_from_subject()
{
  /*
  printTitle("Test from subject") ;
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();
  delete j;//should not create a leak
  delete i;
  delete meta;
  */
}

int main(void)
{
  test_animal() ;
  test_from_subject() ;
}
