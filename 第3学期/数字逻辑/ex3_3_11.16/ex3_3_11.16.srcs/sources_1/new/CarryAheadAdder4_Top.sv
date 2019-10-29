module CarryAheadAdder4_Top(
    input logic CLK100MHZ,
    input logic [7:0] SW,
    output logic [6:0] A2G,
    output logic [7:0] AN,
    output logic DP
);
    logic cf;
    logic[3:0] s;
    CarryAheadAdder4(SW[7:4], SW[3:0], 'b0, s, cf);
    logic[15:0] x;
    assign x = {SW, 3'b000, cf, s};
    SevenSegmentDisplay(x, CLK100MHZ, AN, DP, A2G);
endmodule
