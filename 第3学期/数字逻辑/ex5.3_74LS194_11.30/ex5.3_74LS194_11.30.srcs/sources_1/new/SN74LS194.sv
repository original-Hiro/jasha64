module SN74LS194 (
    input logic clk,
    input logic clr,
    input logic[1:0] set,
    input logic ds,
    input logic[3:0] P,
    output logic[3:0] Q
);
    always_ff @ (posedge clk, posedge clr)
        if (clr == 1) Q <= 4'b0;
        else
            case (set)
                2'b11: Q <= P;
                2'b10: Q <= {Q[2:0], ds};
                2'b01: Q <= {ds, Q[3:1]};
            endcase
endmodule
