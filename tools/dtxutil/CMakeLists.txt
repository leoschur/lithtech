cmake_minimum_required(VERSION 3.15)

project(DTXUtil)

include_directories(
    ../DEdit/Misc
)

add_library(DTXUtil dtxutil.cpp)
add_executable(DTXConverter main.cpp)
