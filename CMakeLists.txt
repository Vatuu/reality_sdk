cmake_minimum_required(VERSION 3.15)

set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON" FORCE)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILDING ON)

set(VERSION 0.1)

project(
    RSDK-Core
    VERSION ${VERSION}
    LANGUAGES CXX C ASM
)   

set(A_NAME ${PROJECT_NAME}.a)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*/*.cpp)

add_executable(${A_NAME} ${SRC_FILES})

target_include_directories( ${A_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/include/rcp
)