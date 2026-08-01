#ifndef TC_DIALECT
#define TC_DIALECT


include "mlir/IR/OpBase.td"
include "mlir/IR/DialectBase.td"
include "mlir/Interfaces/InferTypeOpInterface.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

def TC_Dialect : Dialect {
    let name = "tc";
    let cppNamespace = "::mlir::tc";
    let summary = "Compute IR: hardware-agnostic tensor operations.";
    let extraClassDeclaration = [{
        void registerTypes();
    }];
    let useDefaultTypePrinterParser = 1;
}

class TC_Op<string mnemonic, list<Trait> traits = []> : Op<TC_Dialect, mnemonic, traits>;


#endif // TC_DIALECT
