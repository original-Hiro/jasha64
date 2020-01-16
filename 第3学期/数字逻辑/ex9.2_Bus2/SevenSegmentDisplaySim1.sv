`timescale 1ns / 1ps
module SevenSegmentDisplaySim1();
    logic [6:0] a2g;
    logic [7:0] an;
    logic dp;
    logic clk1000;
    logic clr;
    
    initial begin clk1000 = 1; clr = 1; #0.001 clr = 0; end
    always #0.001 clk1000 = ~clk1000;
    
    logic [3:0] a;
    logic [3:0] b;
    SevenSegmentDisplay DS(clk1000, clr, {a, 12'b0, b, 12'b0}, an, dp, a2g);
    initial begin a = 4'b1111; b = 4'b0000; end
endmodule
