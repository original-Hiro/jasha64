module TFF_top(
    input logic CLK100MHZ,
    input logic[2:0] SW,
    output logic[1:0] LED
);
    logic clka;
    clkdiv(CLK100MHZ, clka);
    TFF(clka, SW[1], SW[2], SW[0], LED[0], LED[1]);
endmodule
