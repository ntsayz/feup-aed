cmake_minimum_required(VERSION 3.23)
project(feup_aed)

set(CMAKE_CXX_STANDARD 20)

add_executable(feup_aed main.cpp src/Manager.cpp src/Manager.h src/Uc.cpp src/Uc.h src/Class.cpp src/Class.h src/Slot.cpp src/Slot.h src/Student.cpp src/Student.h src/Utility.cpp src/Utility.h src/Request.cpp src/Request.h src/Menu.cpp src/Menu.h src/BST.h)

# Doxygen Build
