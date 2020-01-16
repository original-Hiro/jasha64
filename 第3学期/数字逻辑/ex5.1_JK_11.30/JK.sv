module JK(
    input logic clk, set, clr,
    input logic J, K,
    output logic Q,
    output logic notQ
);
    logic JK;
    assign JK = (J & ~Q) | (~K & Q);
    DFF(clk, JK, clr, set, Q, notQ);
endmodule
