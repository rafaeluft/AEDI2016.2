cmake_minimum_required(VERSION 3.6)
project(Aula07-TDStack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.c TDStack.h TDStack.c TDStackcount.c)
add_executable(Aula07TDStack ${SOURCE_FILES})