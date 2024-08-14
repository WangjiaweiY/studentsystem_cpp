#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "score.h"
#include "enum.h"

class Student: public User {
    public:
        Student();
        Student(const string &name, int id, Sex sex, int age);
        Student(const string &name, int id, Sex sex, Score score);
        Score& getScore();
        Sex getSex();
        void showInfo() override;
    private:
        Score score;
};

#endif // STUDENT_H