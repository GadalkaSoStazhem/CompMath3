cmake_minimum_required(VERSION 3.23)
project(CompMath3)

set(CMAKE_CXX_STANDARD 14)

add_executable(CompMath3 main.cpp io.h my_locale.h trapezoid_method.h functions.h checker.h)
