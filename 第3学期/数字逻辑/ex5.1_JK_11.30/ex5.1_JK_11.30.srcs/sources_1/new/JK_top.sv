module JK_top (
    input logic CLK100MHZ,
    input logic[3:0] SW,
    output logic[1:0] LED
);
    logic clka;
    clkdiv(CLK100MHZ, clka);
    JK(clka, SW[3], SW[2], SW[1], SW[0], LED[0], LED[1]);
endmodule
