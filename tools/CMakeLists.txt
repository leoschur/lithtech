cmake_minimum_required (VERSION 2.8)

option(BUILD_DTXUTIL "Build the DTXUtil" ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/sdk/inc
    ${CMAKE_SOURCE_DIR}/libs/stdlith
    ${CMAKE_SOURCE_DIR}/libs/dibmgr
    shared/engine
    shared/model
    shared/packer
    shared/world
)

if(BUILD_DTXUTIL)
    add_subdirectory(dtxutil)
endif()
