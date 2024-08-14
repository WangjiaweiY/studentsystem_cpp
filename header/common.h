#ifndef COMMON_H
#define COMMON_H
#include "enum.h"
#include "user.h"
#include <string>
#include "databasecon.h"
using namespace std;

string sexToString(Sex sex);

void mainMenu(DatabaseConnection db);


#endif // UNTILS_H