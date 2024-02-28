cmake_minimum_required(VERSION 3.14)
project(sorted_collection)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(inc)

add_executable(sorted_collection
        inc/Collection.h
        inc/SortedCollection.h
        src/Collection.cpp
        src/SortedCollection.cpp
        src/CollectionTest.cpp)
