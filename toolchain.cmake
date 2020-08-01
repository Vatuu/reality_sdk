include(CMakeForceCompiler)

set(TOOLCHAIN_PREFIX ${CMAKE_SOURCE_DIR}/../compiler)
set(TOOLCHAIN_BIN ${TOOLCHAIN_PREFIX}/bin)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR mips64)

set(CMAKE_C_STANDARD 18)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C++_STANDARD 20)
set(CMAKE_C++_STANDARD_REQUIRED TRUE)

macro(SET_COMPILER var name)
    find_program(CMAKE_${var} mips64-elf-${name} HINTS ${TOOLCHAIN_BIN} DOC "${name} tool")
endmacro()

if(NOT CMAKE_C_COMPILER)
    SET_COMPILER(C_COMPILER gcc)
endif()

if(NOT CMAKE_C++_COMPILER)
    SET_COMPILER(C++_COMPILER g++)
endif()

if(NOT CMAKE_ASM_COMPILER)
    SET_COMPILER(ASM_COMPILER gcc)
    SET_COMPILER(ASM-ATT_COMPILER as)
endif() 

include_directories(
    ${TOOLCHAIN_PREFIX}/include
)

set(MCPU_FLAGS "-march=vr4300 -mtune=vr4300")

set(CMAKE_C_C++_FLAGS "${MCPU_FLAGS} -mno-long-calls -Wall -Wno-pointer-sign")
set(CMAKE_C_C++_FLAGS_DEBUG   "-O0 -g -ggdb3")
set(CMAKE_C_C++_FLAGS_RELEASE "-O2") 

set(CMAKE_C_FLAGS "${CMAKE_C_C++_FLAGS}" CACHE INTERNAL "c compiler flags")
set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_C++_FLAGS_DEBUG}" )
set(CMAKE_C_FLAGS_RELEASE " ${CMAKE_C_C++_FLAGS_RELEASE}" )

set(CMAKE_C++_FLAGS "${CMAKE_C_C++_FLAGS}" CACHE INTERNAL "C++ compiler flags")
set(CMAKE_C++_FLAGS_DEBUG   "${CMAKE_C_C++_FLAGS_DEBUG}" )
set(CMAKE_C++_FLAGS_RELEASE "${CMAKE_C_C++_FLAGS_RELEASE}" )

set(CMAKE_ASM_FLAGS "${MCPU_FLAGS}" CACHE INTERNAL "asm compiler flags")
set(CMAKE_ASM_FLAGS_DEBUG   "" )
set(CMAKE_ASM_FLAGS_RELEASE "" )