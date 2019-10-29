module SevenSegmentDisplay_Top(
    input [3:0] SW,
    output [7:0] AN,
    output DP,
    output reg [6:0] A2G
);
    SevenSegmentDisplay(SW, AN, DP, A2G);
endmodule
