#include "../header/user.h"
#include <iostream>
#include <string>
#include "../header/enum.h"

using namespace std;

string User::getName() {
    return this->name;
}

int User::getId() {
    return this->id;
}

Sex User::getSex() {
    return this->sex;
}

int User::getAge() {
    return this->age;
}

void User::setId(int id) {
    this->id = id;
}

void User::setName(string name) {
    this->name = name;
}

void User::setSex(Sex sex) {
    this->sex = sex;
}

void User::setAge(int age) {
    this->age = age;
}

void User::showInfo() {
    cout << "id: " << this->id << endl;
    cout << "name: " << this->name << endl;
    cout << "sex: " << this->sex << endl;
}