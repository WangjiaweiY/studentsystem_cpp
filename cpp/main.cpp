#include "../header/student.h"
#include "../header/enum.h"
#include "../header/teacher.h"
#include "../header/databasecon.h"
#include "../header/common.h"
#include <iostream>

using namespace std;

int main() {
    DatabaseConnection db("localhost", "root", "1234", "studentsystem_cpp", 3306);

    if (db.connect()) {
        cout << "Connected to the database successfully." << endl;
        mainMenu(db);
    } else {
        cerr << "Failed to connect to the database." << endl;
    }
    return 0;
}