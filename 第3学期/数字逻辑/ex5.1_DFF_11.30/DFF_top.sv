module DFF_top(
    input logic CLK100MHZ,
    input logic[2:0] SW,
    output logic[1:0] LED
);
    logic clk;
    clkdiv(CLK100MHZ, clk);
    DFF(clk, SW[0], SW[1], SW[2], LED[0], LED[1]);
endmodule
