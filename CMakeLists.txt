cmake_minimum_required(VERSION 4.2.3)
project(tensor-compiler)

find_package(MLIR REQUIRED CONFIG)


list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
include(AddMLIR)

add_subdirectory(include)
add_subdirectory(lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(tools)

# target_include_directories(matmul-lower PRIVATE 
#     ${MLIR_INCLUDE_DIRS}
#     ${LLVM_INCLUDE_DIRS}
#     /home/bradenhelmer/dev/tools/llvm/llvm-build/include
# )
#
# target_link_libraries(matmul-lower PRIVATE
#     MLIRAnalysis
#     MLIRFunctionInterfaces
#     MLIRIR
#     MLIRLinalgDialect
#     MLIRMemRefDialect
#     MLIRAffineDialect
#     MLIRArithDialect
#     MLIRPass
#     MLIRTransforms
#     MLIRParser
#     MLIRSupport
# )
