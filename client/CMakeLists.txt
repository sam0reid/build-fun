
cmake_minimum_required(VERSION 3.20)
project(client)
set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/../install)
find_package(calculator REQUIRED)

add_executable(client ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)

target_link_libraries(client PUBLIC calculator::calculator)