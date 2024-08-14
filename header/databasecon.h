#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include "../include/mysql.h"
#include "../header/student.h"
#include <string>

class DatabaseConnection {
private:
    MYSQL *conn_;
    std::string server_;
    std::string user_;
    std::string password_;
    std::string database_;
    unsigned int port_;

    

public:
    DatabaseConnection(const std::string &server, const std::string &user,
                       const std::string &password, const std::string &database,
                       unsigned int port);
    ~DatabaseConnection(); // 析构函数，用于关闭连接
    bool connect();

    bool executeQuery(const std::string &query); // 执行SQL查询
    void fetchAndPrintResults(); // 获取并打印结果集
    bool queryTable(const std::string &tableName); 
    bool addStudent(const std::string &tableName, Student &student);
    bool deleteStudentById(const std::string &tableName, int studentId);

};

#endif // DATABASECONNECTION_H