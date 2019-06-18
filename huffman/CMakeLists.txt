cmake_minimum_required(VERSION 3.9)
project(huffman)

set(CMAKE_CXX_STANDARD 11)

add_executable(huffman main.cpp Huffman.cpp Huffman.h MetaHandler.cpp MetaHandler.h Parse.h Singleton.cpp Singleton.h)

find_package(Boost COMPONENTS system REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
    set (Boost_USE_STATIC_LIBS ON)

endif()