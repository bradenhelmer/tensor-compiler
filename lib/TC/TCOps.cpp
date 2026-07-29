#include "TC/TCOps.h"

#define GET_OP_CLASSES
#include "TC/TCOps.cpp.inc"

using namespace mlir;
using namespace mlir::tc;

LogicalResult MatMulOp::verify() {

  auto lhsShape = getLhs().getType().getShape();
  auto rhsShape = getRhs().getType().getShape();

  if (lhsShape.size() != 2 || rhsShape.size() != 2) {
    return emitOpError("MatMulOp requires two-dimensional tensors");
  }

  if (lhsShape[1] != rhsShape[0]) {
    return emitOpError(
        "MatMulOp requires shape compatibility: (M,K) x (K,N) -> (M,N)");

    return success();
  }
}
