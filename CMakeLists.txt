cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(cmdNote VERSION 0.1)
configure_file(cmdNoteConfig.h.in cmdNoteConfig.h)
add_executable(cmdNote Source.cpp Write.cpp Read.cpp)
target_include_directories(cmdNote PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
