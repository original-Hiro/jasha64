module clkdiv(
    input logic mclk,
    output logic clka
);
    logic[28:0] q;
    always_ff @ (posedge mclk) q <= q + 1;
    assign clka = q[26];
endmodule
