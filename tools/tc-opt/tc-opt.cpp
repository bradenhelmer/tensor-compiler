#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"

#include "TC/TCDialect.h"
#include "TC/TCOps.h"

#define UNKNOWN_LOC builder.getUnknownLoc()

int main(int argc, char *argv[]) {

  mlir::DialectRegistry registry;
  registry.insert<mlir::tc::TCDialect, mlir::arith::ArithDialect,
                  mlir::func::FuncDialect>();

  // mlir::MLIRContext ctx;
  // ctx.appendDialectRegistry(registry);
  // ctx.loadDialect<mlir::tc::TCDialect, mlir::arith::ArithDialect,
  //                 mlir::func::FuncDialect>();
  // mlir::OpBuilder builder(&ctx);
  // auto func = mlir::func::FuncOp::create(UNKNOWN_LOC, "matmul_roundtrip",
  //                                        builder.getFunctionType({}, {}));
  // builder.setInsertionPointToStart(func.addEntryBlock());
  //
  // auto a = mlir::tc::TensorEmptyOp::create(builder, UNKNOWN_LOC, {2, 2},
  //                                          builder.getF64Type());
  // auto b = mlir::tc::TensorEmptyOp::create(builder, UNKNOWN_LOC, {2, 2},
  //                                          builder.getF64Type());
  // auto c = mlir::tc::TensorEmptyOp::create(builder, UNKNOWN_LOC, {2, 2},
  //                                          builder.getF64Type());
  //
  // auto mm = mlir::tc::MatMulOp::create(builder, UNKNOWN_LOC, c.getType(), a, b);
  // func->dump();
  // return 0;
  return mlir::asMainReturnCode(
      mlir::MlirOptMain(argc, argv, "Tensor Compiler Optimizer", registry));
}
