module TFF(
    input logic clk, clr, set, T,
    output logic Q, notQ
);
    logic DT;
    assign DT = T ^ Q;
    DFF(clk, DT, clr, set, Q, notQ);
endmodule
