#include <iostream>
#include "Node.h"
#include "Student.h"

// This program creates some students, adds them to the linked lists, then removes one.
// Brandon Huynh, last edited 10/30/2024

using namespace std;

void addStudent(Student* newStudent, Node* &head);
void printStudents(Node* head);
void removeStudent(Student* oldStudent, Node* head);

int main() {
  // Creating Students
  Student* Student1 = new Student();
  int id = 467573;
  Student1->setID(id);
  Student* Student2 = new Student();
  int id2 = 456223;
  Student2->setID(id2);
  Student* Student3 = new Student();
  int id3 = 456224;
  Student3->setID(id3);
  // Creating head of list
  Node* head = NULL;
  //add students
  cout << "All students:" << endl;
  addStudent(Student1, head);
  addStudent(Student2, head);
  addStudent(Student3, head);
  printStudents(head);
  //remove students
  cout << "Students minus the second one" << endl;
  removeStudent(Student2, head);
  printStudents(head);
}
void addStudent(Student* newStudent, Node* &head) {
  Node* current = head;
  // in case the list is empty, make the head the new student
  if (current == NULL) {
    head = new Node();
    cout << "adding student: " << newStudent->getID() << endl;
    head->setStudent(newStudent);
  }
  else {
    // traverse to the end of the list
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    //add a new node to the end with the student
    current->setNext(new Node());
      cout << "adding student: " << newStudent->getID() << endl;
      current->getNext()->setStudent(newStudent);
  }
}
void printStudents(Node* head) {
  Node* current = head;
  // traverse through the list, print each students id
  while (current != NULL) {
    cout << current->getStudent()->getID() << endl;
    current = current->getNext();
  }
}

void removeStudent(Student* oldStudent, Node* head) {
  //in case there's no students.
  if (head == NULL) {
    cout << "There's no students...";
    return;
  }
  // store previous and current - current will later occupy the node that wants to be deleted
  Node* previous = head;
  Node* current = head->getNext();
  // traverse through list
  while (current != NULL) {
    // the student is found
    if (current->getStudent() == oldStudent) {
      // if deleting the last node
      if (current->getNext() == NULL) {
	previous->setNext(NULL);
	delete current;
	return;
      }
      //otherwise, link the previous node to skip current (as it's going to be deleted)
      else {
	Node* toAdd = current->getNext();
	previous->setNext(toAdd);
	delete current;
	return;
      }
    }
    else {
      // move to next node
      previous = current;
      current = current->getNext();
    }
  }
}
