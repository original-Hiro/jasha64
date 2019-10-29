`timescale 1ns / 1ps
module Bus2Sim1();
    logic wen;
    logic [6:0] a2g;
    logic [7:0] an;
    logic dp;
    logic clk1000;
    logic clr;
    
    initial begin clk1000 = 1; clr = 1; #0.001 clr = 0; end
    always #0.001 clk1000 = ~clk1000;
    
    logic [3:0] addr;
    logic [3:0] in;
    logic [3:0] out;
    RAM RA(clk1000, clr, wen, addr, in, out);
    
    logic [3:0] disp;
    always_comb
        if (wen) disp = in;
        else disp = out;
    SevenSegmentDisplay DS(clk1000, clr, {addr, 12'b0, disp, 12'b0}, an, dp, a2g);
    
    initial
    begin
    addr = 1; in = 1; wen = 1;
    #1 addr = 1; wen = 0;
    #1 addr = 0; in = 15; wen = 1;
    #1 addr = 0; wen = 0;
    #1 addr = 1;
    end
endmodule
