add_mlir_dialect_library(
  MLIRTC
  TCDialect.cpp
  TCOps.cpp
  TCTypes.cpp
  DEPENDS
  MLIRTCOpsIncGen
  LINK_LIBS
  PUBLIC
  MLIRIR)

target_include_directories(MLIRTC PRIVATE
  ${PROJECT_SOURCE_DIR}/include
  ${CMAKE_BINARY_DIR}/include
  ${MLIR_INCLUDE_DIRS}
  ${LLVM_INCLUDE_DIRS}
)
