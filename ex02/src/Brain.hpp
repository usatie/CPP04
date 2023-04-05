#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#define NUM_OF_IDEAS 100

class Brain {
 public:
  Brain();
  Brain(const Brain& b);
  Brain& operator=(const Brain& b);
  ~Brain();
  std::string getIdea(int i) const;
  void addIdea(const std::string& idea);

 private:
  std::string _ideas[NUM_OF_IDEAS];
  int _i;
};

std::ostream& operator<<(std::ostream& os, const Brain& b);
std::ostream& operator<<(std::ostream& os, const Brain* b);

#endif
