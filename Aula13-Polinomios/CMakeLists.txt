cmake_minimum_required(VERSION 3.6)
project(Aula13-Polinomio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.c GDList.h GDList.c)
add_executable(Aula13Polinomio ${SOURCE_FILES})
