cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
project(cmdNote VERSION 0.1)
configure_file(cmdNoteConfig.h.in cmdNoteConfig.h)
add_executable(cmdNote Source.cpp noteFuncs.cpp)
target_include_directories(cmdNote PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
