module Module74LS173_top(
    input logic CLK100MHZ,
    input logic[8:0] SW,
    output logic[3:0] LED
);
    logic clka;
    clkdiv(CLK100MHZ, clka);
    Module74LS173(clka, SW[6], SW[5:4], SW[8:7], SW[3:0], LED[3:0]);
endmodule
