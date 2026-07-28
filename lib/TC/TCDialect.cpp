#include "TC/TCDialect.h"
#include "TC/TCTypes.h"
#include "TC/TCOps.h"

using namespace mlir;
using namespace mlir::tc;

#include "TC/TCOpsDialect.cpp.inc"

void TCDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "TC/TCOps.cpp.inc"
      >();
  registerTypes();
}
