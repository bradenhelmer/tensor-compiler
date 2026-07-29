cmake_minimum_required(VERSION 4.2.3)
project(tensor-compiler LANGUAGES CXX C)

find_package(MLIR REQUIRED CONFIG)

list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
include(AddMLIR)
include(AddLLVM)
include(TableGen)

set(TC_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(TC_BINARY_DIR ${PROJECT_BINARY_DIR})
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})
include_directories(${TC_SOURCE_DIR}/include)
include_directories(${TC_BINARY_DIR}/include)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(tools)

file(GLOB_RECURSE TC_CXX_SRCS
     ${CMAKE_SOURCE_DIR}/include/TC/*.h
     ${CMAKE_SOURCE_DIR}/include/TC/*.cpp
     ${CMAKE_SOURCE_DIR}/lib/TC/*.h
     ${CMAKE_SOURCE_DIR}/lib/TC/*.cpp
     ${CMAKE_SOURCE_DIR}/tools/*.h
     ${CMAKE_SOURCE_DIR}/tools/*.cpp)

add_custom_target(format
    COMMAND clang-format -i -style=file ${TC_CXX_SRCS}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Formatting C++ sources with clang-format"
)

add_custom_target(check-format
    COMMAND clang-format --dry-run --Werror -style=file ${TC_CXX_SRCS}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Checking C++ sources comply with clang-format"
)
