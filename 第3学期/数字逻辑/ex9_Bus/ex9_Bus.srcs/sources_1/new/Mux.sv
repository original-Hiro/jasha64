module Mux
    #(parameter N)
    (input logic [3:0] in[2**N-1:0],
    input logic [N-1:0] sel,
    output logic [3:0] out);
    assign out = in[sel];
endmodule
