#ifndef USER_H
#define USER_H
#include <string>
#include "enum.h"

using namespace std;

class User {
    public:
        virtual void showInfo();
        void setName(string name);
        void setId(int id);
        void setSex(Sex sex);
        void setAge(int age);
        string getName();
        int getId();
        Sex getSex();
        int getAge();
    protected:
        int id;
        string name;
        int age;
        Sex sex;
};

#endif // USER_H