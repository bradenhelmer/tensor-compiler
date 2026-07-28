#ifndef TC_OPS
#define TC_OPS

include "TCTypes.td"


def TC_MatMulOp : TC_Op<"matmul", [Pure]> {
    let summary = "Matrix multiplication over tensors";
    let arguments = (ins TC_Tensor:$lhs, TC_Tensor:$rhs);
    let results = (outs TC_Tensor:$result);

    let hasVerifier = 1;  // shape compatibility: (M,K) x (K,N) -> (M,N)
}


#endif // TC_OPS
