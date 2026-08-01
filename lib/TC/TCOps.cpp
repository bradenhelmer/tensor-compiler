#include "TC/TCOps.h"

#define GET_OP_CLASSES
#include "TC/TCOps.cpp.inc"

using namespace llvm;
using namespace mlir;
using namespace mlir::tc;

void mlir::tc::TensorEmptyOp::build(OpBuilder &builder, OperationState &state,
                                    ArrayRef<int64_t> shape, Type elementType) {
  auto type = TC_TensorType::get(builder.getContext(), shape, elementType);
  return build(builder, state, type);
}

LogicalResult MatMulOp::verify() {

  auto lhsShape = getA().getType().getShape();
  auto rhsShape = getB().getType().getShape();

  if (lhsShape.size() != 2 || rhsShape.size() != 2) {
    return emitOpError("MatMulOp requires two-dimensional tensors");
  }

  if (lhsShape[1] != rhsShape[0]) {
    return emitOpError(
        "MatMulOp requires shape compatibility: (M,K) x (K,N) -> (M,N)");
  }
  return success();
}
