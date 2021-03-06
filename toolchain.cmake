include(CMakeForceCompiler)

set(TOOLCHAIN_PREFIX ${CMAKE_SOURCE_DIR}/../compiler)
set(TOOLCHAIN_BIN ${TOOLCHAIN_PREFIX}/bin)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR mips64)

if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8.0)
    set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std=c++20")
    set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std=gnu++20")
elseif (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.1)
    set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std=c++2z")
    set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std=gnu++2z")
endif()

macro(SET_COMPILER var name)
    find_program(CMAKE_${var} mips64-elf-${name} HINTS ${TOOLCHAIN_BIN} DOC "${name} tool")
endmacro()

if(NOT CMAKE_C_COMPILER)
    SET_COMPILER(C_COMPILER gcc)
endif()

if(NOT CMAKE_CXX_COMPILER)
    SET_COMPILER(CXX_COMPILER g++)
endif()

if(NOT CMAKE_ASM_COMPILER)
    SET_COMPILER(ASM_COMPILER gcc)
    SET_COMPILER(ASM-ATT_COMPILER as)
endif() 

include_directories(
    ${TOOLCHAIN_PREFIX}/include
)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(MCPU_FLAGS "-march=vr4300 -mtune=vr4300")

set(CMAKE_C_CXX_FLAGS "${MCPU_FLAGS} -mno-long-calls -Wall -Wno-unknown-pragmas -nostdlib")
set(CMAKE_C_CXX_FLAGS_DEBUG   "-g -ggdb3")
set(CMAKE_C_CXX_FLAGS_RELEASE "-O2") 

set(CMAKE_C_FLAGS "${CMAKE_C_CXX_FLAGS}" CACHE INTERNAL "c compiler flags")
set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_CXX_FLAGS_DEBUG}" )
set(CMAKE_C_FLAGS_RELEASE " ${CMAKE_C_CXX_FLAGS_RELEASE}" )

set(CMAKE_CXX_FLAGS "${CMAKE_C_CXX_FLAGS}" CACHE INTERNAL "CXX compiler flags")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_C_CXX_FLAGS_DEBUG}" )
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_CXX_FLAGS_RELEASE}" )

set(CMAKE_ASM_FLAGS "${MCPU_FLAGS}" CACHE INTERNAL "asm compiler flags")
set(CMAKE_ASM_FLAGS_DEBUG   "" )
set(CMAKE_ASM_FLAGS_RELEASE "" )