module DFF(
    input logic clk,
    input logic D,
    input logic clr,
    input logic set,
    output logic Q,
    output logic notQ
);
    assign notQ = ~Q;
    always_ff @ (posedge clk, negedge clr, negedge set)
        if (set == 0) Q <= 1;
        else if (clr == 0) Q <= 0;
        else Q <= D;
endmodule
