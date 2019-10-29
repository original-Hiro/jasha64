`timescale 1ns / 1ps
module TrafficSim1();
    logic clk100mhz, clr;
    logic [5:0] out;
    logic _15s, _45s, clk1;
    initial clk100mhz = 0;
    initial
        begin
            clr = 1;
            #0.001 clr = 0;
        end
    always #0.001 clk100mhz = ~clk100mhz;
    clkdiv C1(clk100mhz, clr, clk1);
    clock_pulse C2(clk1, clr, _15s, _45s);
    Traffic T(_15s, _45s, clr, out);
endmodule
