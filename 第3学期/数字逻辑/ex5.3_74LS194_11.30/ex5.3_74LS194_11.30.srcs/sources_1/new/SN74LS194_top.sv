module SN74LS194_top(
    input logic CLK100MHZ,
    input logic[7:0] SW,
    output logic[3:0] LED
);
    logic clka;
    clkdiv(CLK100MHZ, clka);
    SN74LS194(clka, SW[7], SW[6:5], SW[4], SW[3:0], LED[3:0]);
endmodule
