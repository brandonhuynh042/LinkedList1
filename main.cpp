#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

void addStudent(Student* newStudent, Node* &head);
void printStudents(Node* head);
void removeStudent(Student* oldStudent, Node* head);

int main() {
  Student* Student1 = new Student();
  int id = 467573;
  Student1->setID(id);
  Student* Student2 = new Student();
  int id2 = 456223;
  Student2->setID(id2);
  Student* Student3 = new Student();
  int id3 = 456224;
  Student3->setID(id3);
  Node* head = NULL;
  addStudent(Student1, head);
  addStudent(Student2, head);
  addStudent(Student3, head);
  printStudents(head);
  removeStudent(Student2, head);
  printStudents(head);
}
void addStudent(Student* newStudent, Node* &head) {
  Node* current = head;
  if (current == NULL) {
    head = new Node();
    cout << "adding student! " << newStudent->getID() << endl;
    head->setStudent(newStudent);
  }
  else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new Node());
      cout << "adding student: " << newStudent->getID() << endl;
      current->getNext()->setStudent(newStudent);
  }
}
void printStudents(Node* head) {
  Node* current = head;
  while (current != NULL) {
    cout << current->getStudent()->getID() << endl;
    current = current->getNext();
  }
}

// fix the memory leak...
void removeStudent(Student* oldStudent, Node* head) {
  if (head == NULL) {
    cout << "There's no students...";
    return;
  }
  Node* previous;
  Node* current = head;
  while (current != NULL) {
    if (current->getNext()->getStudent() == oldStudent) {
      cout << "found." << endl;
      if (current->getNext()->getNext() == NULL) {
	current->setNext(NULL);	
	return;
      }
      else {
	Node* toAdd = current->getNext()->getNext();
	current->setNext(toAdd);
	return;
      }
    }
    else {
      previous = current;
      current = current->getNext();
    }
  }
}
