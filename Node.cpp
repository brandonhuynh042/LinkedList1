#include <iostream>
#include "Node.h"

Node::Node() {
  next = NULL;
  student = NULL;
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
