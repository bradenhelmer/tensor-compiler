#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"

#include "TC/TCDialect.h"

int main(int argc, char *argv[]) {

  mlir::DialectRegistry registry;
  registry.insert<mlir::tc::TCDialect, mlir::arith::ArithDialect,
                  mlir::func::FuncDialect>();
  return mlir::asMainReturnCode(
      mlir::MlirOptMain(argc, argv, "Tensor Compiler Optimizer", registry));
}
