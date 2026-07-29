#include "TC/TCOps.h"

#define GET_OP_CLASSES
#include "TC/TCOps.cpp.inc"

using namespace mlir;
using namespace mlir::tc;

LogicalResult MatMulOp::verify() { return success(); }
