#include "TC/TCTypes.h"

using namespace mlir::tc;

#define GET_TYPEDEF_CLASSES
#include "TC/TCOpsTypes.cpp.inc"

void TCDialect::registerTypes() {
  addTypes<
#define GET_TYPEDEF_LIST
#include "TC/TCOpsTypes.cpp.inc"
      >();
}

