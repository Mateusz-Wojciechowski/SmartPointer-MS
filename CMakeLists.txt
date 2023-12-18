cmake_minimum_required(VERSION 3.26)
project(Lab5_TEP)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lab5_TEP main.cpp
        CMySmartPointer.h
        CRefCounter.h
        Tree/CTree.h
        Tree/CUserInterface.h
        Tree/CInterfaceConstants.h
)
