#include "../header/databasecon.h"
#include "../header/common.h"
#include <iostream>

bool DatabaseConnection::connect() {
    conn_ = mysql_init(NULL);
    if (conn_ == NULL) {
        std::cerr << "MySQL init failed" << std::endl;
        return false;
    }

    if (!mysql_real_connect(conn_, server_.c_str(), user_.c_str(), password_.c_str(),
                           database_.c_str(), port_, NULL, 0)) {
        std::cerr << "Connection error: " << mysql_error(conn_) << std::endl;
        return false;
    }
    return true;
}

// 构造函数的定义
DatabaseConnection::DatabaseConnection(const std::string &server, const std::string &user,
                                       const std::string &password, const std::string &database,
                                       unsigned int port)
    : server_(server), user_(user), password_(password), database_(database), port_(port), conn_(NULL) {}

// 析构函数的定义
DatabaseConnection::~DatabaseConnection() {
    if (conn_ != NULL) {
        mysql_close(conn_);
    }
}

// 公有成员函数 executeQuery 的定义
bool DatabaseConnection::executeQuery(const std::string &query) {
    if (mysql_query(conn_, query.c_str())) {
        std::cerr << "Error executing query: " << mysql_error(conn_) << std::endl;
        return false;
    }
    return true;
}

// 公有成员函数 fetchAndPrintResults 的定义
void DatabaseConnection::fetchAndPrintResults() {
    MYSQL_RES *res = mysql_store_result(conn_);
    if (!res) {
        std::cerr << "No results returned or error storing results" << std::endl;
        return;
    }

    int num_fields = mysql_num_fields(res);
    while (MYSQL_ROW row = mysql_fetch_row(res)) {
        for (int i = 0; i < num_fields; i++) {
            std::cout << (row[i] ? row[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
    }

    mysql_free_result(res);
}

bool DatabaseConnection::queryTable(const std::string &tableName) {
    // 构造查询语句
    std::string query = "SELECT * FROM " + tableName;
    
    // 使用已有的 executeQuery 方法执行查询
    return executeQuery(query);
}

bool DatabaseConnection::addStudent(const std::string &tableName, Student &student) {
    // 构造插入语句
    std::string query = "INSERT INTO " + tableName + " (id, name, sex, age) VALUES (";
    query += std::to_string(student.getId()) + ", '";
    query += student.getName() + "', '";
    query += sexToString(student.getSex()) + "', ";
    // query += mysql_escape_string(conn_, student.getName().c_str()) + "', '";
    // query += mysql_escape_string(conn_, student.getSex().c_str()) + "', ";
    query += std::to_string(student.getAge()) + ")";

    // 使用已有的 executeQuery 方法执行插入操作
    return executeQuery(query);
}

bool DatabaseConnection::deleteStudentById(const std::string &tableName, int studentId) {
    // 构造删除语句
    std::string query = "DELETE FROM " + tableName + " WHERE id = ";
    query += std::to_string(studentId);

    // 使用已有的 executeQuery 方法执行删除操作
    return executeQuery(query);
}
