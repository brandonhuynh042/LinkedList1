#include <iostream>
#include "Node.h"

Node::Node(Student* newStudent) {
  next = NULL;
  student = newStudent;
}

Node::~Node() {
  delete student;
  next = NULL;
}

void Node::setStudent(Student* newStudent) {
  student = newStudent;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* newNode) {
  next = newNode;
}

Node* Node::getNext() {
  return next;
}
