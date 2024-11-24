cmake_minimum_required(VERSION 3.29)
project(du03)

set(CMAKE_CXX_STANDARD 20)

add_executable(du03 main.cpp
        HashTable.cpp
        HashTable.h
        keyValuePair.h
        InterfaceHashFunction.h
        SimpleOwnHashFunction.cpp
        SimpleOwnHashFunction.h
        AdvancedOwnHashFunction.cpp
        AdvancedOwnHashFunction.h)
