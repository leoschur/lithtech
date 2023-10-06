cmake_minimum_required (VERSION 2.8)

project (dibmgr)

include_directories(./)
add_library(dibmgr STATIC dib.cpp dibmgr.cpp dibpal.cpp)
