#include "../header/common.h"
#include <string>
#include <iostream>
#include "../header/user.h"
#include "../header/databasecon.h"
using namespace std;

string sexToString(Sex sex) {  
    switch (sex) {
        case MALE: return "Male";
        case FEMALE: return "Female";
        default: return "Unknown";
    }   
}

void mainMenu(DatabaseConnection db) {
    Student student("aby", 202111111, MALE, 20);
    while(true){
        system("cls");
        cout << "学生信息管理系统" << endl;
        cout << "功能选择：" << endl;
        cout << "1. 查询学生信息  ";
        cout << "2. 查询教师信息" << endl;
        cout << "3. 查询学生成绩  ";
        cout << "4. 修改学生成绩" << endl;
        cout << "5. 删除学生信息  ";
        cout << "6. 新增学生信息" << endl;
        cout << "请输入选项(1-6)：";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                if(db.queryTable("student")) {
                    cout << "    学号" << "\t" << "姓名" << "\t" << "性别" << "\t" << "年龄" << "\t" << endl;
                    db.fetchAndPrintResults();
                }
                system("pause");
                break;
            case 2:
                if(db.queryTable("teacher")) {
                    cout << "  工号" << "\t" << "姓名" << "\t" << "性别" << "\t" << "年龄" << "\t" << endl;
                    db.fetchAndPrintResults();
                }
                system("pause");
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                cout << "请输入要删除的学生ID：";
                int studentIdToDelete;
                cin >> studentIdToDelete;
                if (db.deleteStudentById("student", studentIdToDelete)) {
                    std::cout << "Student with ID " << studentIdToDelete << " deleted successfully." << std::endl;
                } else {
                    std::cerr << "Failed to delete student with ID " << studentIdToDelete << "." << std::endl;
                }
                system("pause");
                break;
            case 6:
                if (db.addStudent("student", student)) {
                    std::cout << "Student added successfully." << std::endl;
                } else {
                    std::cerr << "Failed to add student." << std::endl;
                }
                system("pause");
                break;
            default:
                cout << "无效的选项，请重新输入！" << endl;
                break;
        }
    }
}
