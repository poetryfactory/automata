cmake_minimum_required(VERSION 3.15)
project(ccc)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ccc
        main.cpp
DFA.cpp
DFA.h
NFA.cpp
NFA.h
State.cpp
State.h
Transition.cpp
Transition.h
RG.cpp
RG.h
global.h
FA.cpp
FA.h
helper.cpp)
