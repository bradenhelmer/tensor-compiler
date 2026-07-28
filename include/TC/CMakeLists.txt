include_directories(${MLIR_INCLUDE_DIRS})
add_mlir_dialect(TCOps tc)
add_mlir_doc(TCDialect TCDialect TC/ -gen-dialect-doc)
add_mlir_doc(TCOps TCOps TC/ -gen-op-doc)
