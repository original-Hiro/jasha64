module FullAdder_Top(
    input logic SW[2:0],
    output logic LED[1:0]
);
    FullAdder(SW[2], SW[1], SW[0], LED[0], LED[1]);
endmodule
