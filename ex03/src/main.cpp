#include <iomanip>
#include <iostream>

#include "Character.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

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

// print test subtitle in white color surrounded by '-'
void printSubtitle(std::string const& subtitle) {
  // print '-'
  std::cout << std::setfill('-') << std::setw(80) << "" << std::endl;
  // print subtitle at the center
  std::cout << std::setfill(' ') << std::setw(40 - subtitle.length() / 2) << ""
            << subtitle << std::endl;
  // print '-'
  std::cout << std::setfill('-') << std::setw(80) << "" << std::endl;
  // reset color
  std::cout << RESET << std::setfill(' ') << std::setw(0);
}

void test_ice() {
  printTitle("Test Ice");
  // Test Orthodox canonical form
  {
    printSubtitle("Test Orthodox canonical form");
    Ice ice1;
    Ice ice2(ice1);
    Ice ice3 = ice1;
    ice3 = ice1;
  }
  // Test use
  {
    printSubtitle("Test use");
    Ice ice;
    Character character("character");
    ice.use(character);
  }
  // Test clone
  {
    printSubtitle("Test clone");
    Ice ice;
    AMateria* ice2 = ice.clone();
    delete ice2;
  }
  // Test getType
  {
    printSubtitle("Test getType");
    Ice ice;
    std::cout << ice.getType() << std::endl;
  }
}

void test_materia_source() {
  printTitle("Test MateriaSource");
  // Test Orthodox canonical form
  {
    printSubtitle("Test Orthodox canonical form");
    MateriaSource src1;
    MateriaSource src2(src1);
    MateriaSource src3 = src1;
    src3 = src1;
  }
  // Test learnMateria
  {
    printSubtitle("Test learnMateria");
    MateriaSource src;
    src.learnMateria(new Ice());
    //src.learnMateria(new Cure());
  }
  // Test createMateria
  {
    printSubtitle("Test createMateria");
    MateriaSource src;
    src.learnMateria(new Ice());
    //src.learnMateria(new Cure());
    AMateria* ice = src.createMateria("ice");
    AMateria* cure = src.createMateria("cure");
    AMateria* unknown = src.createMateria("unknown");
    delete ice;
    delete cure;
    delete unknown;
  }
}

void test_character() {
  // Test Orthodox canonical form
  {
    printSubtitle("Test Orthodox canonical form");
    Character character1("character1");
    Character character2(character1);
    Character character3 = character1;
    character3 = character1;
  }
  
  // Test deep copy
  {
    printSubtitle("Test deep copy");
    Character character1("character1");
    character1.equip(new Ice());
    character1.equip(new Ice());
    // All of them should not leak!
    {
      Character character2(character1);
    }
    {
      Character character3 = character1;
    }
    {
      Character character4("character4");
      character4 = character1;
    }
  }

  // Test equip
  {
    printSubtitle("Test equip");
    Character character("character");
    character.equip(new Ice());
    //character.equip(new Cure());
    //character.equip(new Cure());
  }
  
  // Test unequip
  {
    printSubtitle("Test unequip");
    Character character("character");
    character.equip(new Ice());
    //character.equip(new Cure());
    //character.equip(new Cure());
    character.unequip(0);
    character.unequip(1);
    character.unequip(2);
  }

  // Test use
  {
    printSubtitle("Test use");
    Character character("character");
    character.equip(new Ice());
    //character.equip(new Cure());
    //character.equip(new Cure());
    Character target("target");
    character.use(0, target);
    character.use(1, target);
    character.use(2, target);
  }

  // Test getName
  {
    printSubtitle("Test getName");
    Character character("character");
    std::cout << character.getName() << std::endl;
  }

  // Test equip to full inventory
  {
    printSubtitle("Test equip to full inventory");
    Character character("character");
    character.equip(new Ice());
    character.equip(new Ice());
    character.equip(new Ice());
    character.equip(new Ice());

    // This won't be equiped
    Ice *ice = new Ice();
    character.equip(ice);
    delete ice;
  }

  // Test use/unequip an unexisting Materia
  {
    printSubtitle("Test use/unequip an unexisting Materia");
    Character character("character");
    Character target("target");
    character.use(0, target);
    character.unequip(0);
  }
}

void test_from_subject() {
  printTitle("Test from sunject pdf");

  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  // src->learnMateria(new Cure()) ;

  ICharacter* me = new Character("me");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;
}

int main(void) {
  test_ice();
  test_materia_source();
  test_character();
  test_from_subject();
  return 0;
}
