#include "TC/TCTypes.h"
#include "TC/TCDialect.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

using namespace mlir::tc;

#define GET_TYPEDEF_CLASSES
#include "TC/TCOpsTypes.cpp.inc"

void TCDialect::registerTypes() {
  addTypes<
#define GET_TYPEDEF_LIST
#include "TC/TCOpsTypes.cpp.inc"
      >();
}
