//
// Created by mrbru on 10.05.2023.
//

#ifndef DATABASE_SCRIPT_BASE_SQLITE_H
#define DATABASE_SCRIPT_BASE_SQLITE_H

#include <iostream>
#include <string>
#include <assert.h>

#include "sqlite3.h"

void testBd();


bool openBd(const char* bdName);
bool closeBd();
bool request_insert_create(const char* sqlString);
int getLastRowId();
bool request_select(const char* sqlSting);

#endif //DATABASE_SCRIPT_BASE_SQLITE_H
