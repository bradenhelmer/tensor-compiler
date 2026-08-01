"func.func"() <{function_type = () -> (), sym_name = "matmul_roundtrip"}> ({
  %0 = "tc.tensor_empty"() : () -> !tc.tensor<2, 2, f64>
  %1 = "tc.tensor_empty"() : () -> !tc.tensor<2, 2, f64>
  %2 = "tc.tensor_empty"() : () -> !tc.tensor<2, 2, f64>
  %3 = "tc.matmul"(%0, %1) : (!tc.tensor<2, 2, f64>, !tc.tensor<2, 2, f64>) -> !tc.tensor<2, 2, f64>
}) : () -> ()
