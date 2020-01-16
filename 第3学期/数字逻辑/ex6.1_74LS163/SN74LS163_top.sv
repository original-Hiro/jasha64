module _74LS163_top(
    input logic CLK100MHZ,
    input logic [7:0] SW,
    output logic [4:0] LED
);
    logic clka;
    clkdiv(CLK100MHZ, clka);
    _74LS163(SW[7], clka, SW[6], SW[5], SW[4], SW[0], SW[1], SW[2], SW[3], LED[0], LED[1], LED[2], LED[3], LED[4]);
endmodule
