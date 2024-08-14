#include "include/mysql.h"
#include <stdio.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    const char *server = "localhost";
    const char *user = "root";
    const char *password = "1234"; // 替换为你的密码
    const char *database = "studentsystem_cpp";

    conn = mysql_init(NULL);

    // 连接到数据库
    if (!mysql_real_connect(conn, server, user, password, database, 3306, NULL, 0)) {
        fprintf(stderr, "错误: %s\n", mysql_error(conn));
        return 1;
    }

    // 执行查询
    if (mysql_query(conn, "SELECT * FROM student")) { // 替换 your_table 为你的表名
        fprintf(stderr, "错误: %s\n", mysql_error(conn));
        return 1;
    }

    // 获取结果集
    res = mysql_store_result(conn);

    // 遍历结果集
    while ((row = mysql_fetch_row(res)) != NULL) {
        // 输出每行数据
        for (int i = 0; i < mysql_num_fields(res); i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    // 释放结果集
    mysql_free_result(res);

    // 关闭连接
    mysql_close(conn);

    return 0;
}