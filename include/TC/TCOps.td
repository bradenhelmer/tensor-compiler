#ifndef TC_OPS
#define TC_OPS

include "TCTypes.td"


def TC_TensorEmptyOp: TC_Op<"tensor_empty", [Pure]> {
    let summary = "Creates an empty, uninitialized tensor.";
    let results = (outs TC_Tensor:$result);
    let builders = [
       OpBuilder<(ins "ArrayRef<int64_t>":$shape, "Type":$elementType)>
    ];
    //let assemblyFormat = "attr-dict `:` type($result)";
}
def TC_TensorRandOp: TC_Op<"tensor_rand", [Pure]> {}

def TC_MatMulOp : TC_Op<"matmul", [Pure]> {
    let summary = "Matrix multiplication over tensors";
    let arguments = (ins TC_Tensor:$A, TC_Tensor:$B);
    let results = (outs TC_Tensor:$C);

    let hasVerifier = 1;
}


#endif // TC_OPS
