module Bus2Top(
    input logic CLK100MHZ,
    input logic [9:0] SW,
    output logic [6:0] A2G,
    output logic [7:0] AN,
    output logic DP
    //output logic [1:0] LED
    );
    logic clk1;
    clkdiv CD(CLK100MHZ, SW[9], clk1);
    
    logic [3:0] addr;
    logic [3:0] in;
    logic [3:0] out;
    assign addr = SW[7:4];
    assign in = SW[3:0];
    RAM RA(clk1, SW[9], SW[8], addr, in, out);
    
    logic [3:0] disp;
    always_comb
        if (SW[8]) disp = in;
        else disp = out;
    SevenSegmentDisplay DS(CLK100MHZ, SW[9], {addr, 24'b0000_0000_0000_0000_0000_0000, disp}, AN, DP, A2G);//, LED[1:0]);
endmodule
