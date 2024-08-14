#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"

class Teacher: public User {
    public:
        Teacher(const string &name, int id, Sex sex);
        void showInfo() override;
};

#endif // TEACHER_H