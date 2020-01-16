module clkdiv(
    input logic mclk,
    input logic clr,
    output logic clka
);
    logic [26:0] q;
    always_ff @ (posedge mclk, posedge clr)
        if (clr == 1) q <= 0;
        else q <= q + 1;
    assign clka = q[26];
endmodule
