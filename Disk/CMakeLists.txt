cmake_minimum_required(VERSION 3.14)
project(Disk)

set(CMAKE_CXX_STANDARD 14)

add_executable(Disk main.cpp DataBaseHandler.cpp DataBaseHandler.h Singleton.cpp Singleton.h Parse.h DataStructures/LinkedList.h DataStructures/Node.h ImageHandler.cpp ImageHandler.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML COMPONENTS System Window Graphics Network Audio  REQUIRED )

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Disk ${SFML_LIBRARIES})
endif()

find_package(Boost COMPONENTS system REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
    set (Boost_USE_STATIC_LIBS ON)

endif()