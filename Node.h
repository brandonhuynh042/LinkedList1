#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"
using namespace std;

class Node {
 public:
  Node(Student* newStudent);                  // constructor
  ~Node();                                    // destructor
  void setStudent (Student* newStudent);      // setting the value of the node
  Student* getStudent();                      // getting the value of the node
  void setNext(Node* newNext);                // setting the next node
  Node* getNext();                            // getting the next node
 protected:
  Student* student;                           // value which the node holds
  Node* next;                                 // stores next node in list
};
#endif
