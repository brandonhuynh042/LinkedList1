#include <iostream>
#include "Student.h"

using namespace std;

Student::Student() {
  id = 0;
}

void Student::setID(int newID) {
  id = newID;
}

int Student::getID() {
  return id;
}
