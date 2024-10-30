#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"
using namespace std;

class Node {
 public:
  Node();
  ~Node();
  void setStudent (Student* newStudent);
  Student* getStudent();
  void setNext(Node* newNext);
  Node* getNext();
 private:
  Student* student;
  Node* next;
};
#endif
