`timescale 1ns / 1ps
module DigitalClockSim1();
    logic clk;
    logic [2:0] sw;
    logic [6:0] a2g;
    logic [7:0] an;
    logic dp;
    DigitalClock_Top DC(clk, sw, a2g, an, dp);
    
    always sw[2:1] = 0;
    initial begin sw[0] = 1; #1 sw[0] = 0; end
    initial clk = 0;
    always #1 clk = ~clk;
endmodule
