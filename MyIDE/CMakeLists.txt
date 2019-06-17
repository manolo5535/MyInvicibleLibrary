cmake_minimum_required(VERSION 2.8.4)
project(MyIDE)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp   Singleton.cpp Menu.cpp Menu.h DataStructures/LinkedList.h DataStructures/Node.h  Singleton.h ImagenHandler.cpp ImagenHandler.h GaleryHandler.cpp GaleryHandler.h MetaDataHandler.cpp MetaDataHandler.h)
add_executable(MyIDE ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmakeModules")

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(MyIDE ${SFML_LIBRARIES})
endif()
