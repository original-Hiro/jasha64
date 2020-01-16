`timescale 1ns / 1ps
module DigitalClockSim1();
    logic clk;
    logic sw;
    logic [6:0] a2g;
    logic [3:0] an;
    logic dp;
    DigitalClock_Top DC(clk, sw, a2g, an, dp);
    
    initial begin sw = 1; #1 sw = 0; end
    initial clk = 0;
    always #1 clk = ~clk;
endmodule
