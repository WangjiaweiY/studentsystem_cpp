#include "../header/student.h"
#include <iostream>
#include "../header/enum.h"
#include "../header/common.h"
#include "../header/score.h"

using namespace std;

Student::Student(const string &name, int id, Sex sex, int age) {
    this->name = name;
    this->id = id;
    this->sex = sex;
    this->score = Score();
    this->age = age;
}

Student::Student(const string &name, int id, Sex sex, Score score) {
    this->name = name;
    this->id = id;
    this->sex = sex;
    this->score = score;
}

void Student::showInfo() {
    cout << "Student Name: " << name << ", ID: " << id << ", Sex: " << sexToString(sex) << " " << this->score.printAllScore() << endl;
}

Score& Student::getScore() {
    return score;
}

Sex Student::getSex() {
    return sex;
}


