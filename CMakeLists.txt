cmake_minimum_required(VERSION 3.15)

set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON" FORCE)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILDING ON)

set(VERSION 0.1)

project(
    RSDK-Core
    VERSION ${VERSION}
    LANGUAGES C C++ ASM
)   

set(A_NAME ${PROJECT_NAME}.a)

add_executable(${A_NAME})

target_sources(${A_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/src/**
)

target_include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/include/**
)