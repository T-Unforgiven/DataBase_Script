cmake_minimum_required(VERSION 3.24)
project(DataBase_Script)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataBase_Script main.cpp base_sqlite.h base_sqlite.cpp sqlite3.h sqlite3.c bd.h DATA.h bd.cpp)
