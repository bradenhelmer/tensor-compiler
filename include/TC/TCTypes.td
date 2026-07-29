#ifndef TC_TYPES_H
#define TC_TYPES_H

include "mlir/IR/AttrTypeBase.td"
include "TCDialect.td"

class TCType<string name, string typeMnemonic, list<Trait> traits = []>
    : TypeDef<TC_Dialect, name, traits> {
  let mnemonic = typeMnemonic;
}


def TC_Tensor : TCType<"TC_Tensor", "tensor"> {
  let summary = "A tensor type in the TC dialect.";
  let description = "Represents a tensor type in the TC dialect.";
  let parameters = (ins
    ArrayRefParameter<"int64_t">:$shape,
    "Type":$elementType
  );

  let assemblyFormat = "`<` $shape `,` $elementType `>`";
}


#endif // TC_TYPES_H
