cmake_minimum_required(VERSION 3.31)
project(logger)

set(CMAKE_CXX_STANDARD 20)

add_library(logger STATIC src/logger.cpp)
target_include_directories(logger
        PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}/include"
        PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library(jlizard::logger ALIAS logger)

enable_testing()
include(tests.cmake)