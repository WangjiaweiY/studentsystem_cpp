#include "../header/teacher.h"
#include <iostream>
#include "../header/enum.h"
#include "../header/common.h"

using namespace std;

Teacher::Teacher(const string &name, int id, Sex sex) {
    this->name = name;
    this->id = id;
    this->sex = sex;
}

void Teacher::showInfo() {
    cout << "Teacher Name: " << name << ", ID: " << id << ", Sex: " << sexToString(sex) << endl;
}