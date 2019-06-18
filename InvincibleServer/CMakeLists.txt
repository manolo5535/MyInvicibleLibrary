cmake_minimum_required(VERSION 3.14)
project(InvincibleServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(InvincibleServer main.cpp DataStructures/LinkedList.h DataStructures/Node.h Controller.cpp Controller.h ImageHandler.cpp ImageHandler.h FaultTolerance.cpp FaultTolerance.h Singleton.cpp Singleton.h DataBase.cpp DataBase.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(InvincibleServer ${SFML_LIBRARIES})
endif()
