module ALU_top(
    input logic[15:0] SW,
    output logic[5:0] LED
);
    ALU(SW[3:0], SW[7:4], SW[8], SW[14:13], SW[15], LED[3:0], LED[4], LED[5]);
endmodule
