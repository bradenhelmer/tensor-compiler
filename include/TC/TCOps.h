#ifndef TC_TCOPS_H
#define TC_TCOPS_H

#include "TC/TCTypes.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/Interfaces/InferTypeOpInterface.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#define GET_OP_CLASSES
#include "TC/TCOps.h.inc"

#endif // TC_TCOPS_H
