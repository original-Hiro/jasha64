module TrafficTop(
    input logic CLK100MHZ,
    input logic BTNC,
    output logic [5:0] LIGHTS
    );
    logic _5s, _10s, clk1;
    clkdiv C1(CLK100MHZ, BTNC, clk1);
    clock_pulse C2(clk1, BTNC, _5s, _10s);
    Traffic T(clk1, _5s, _10s, BTNC, LIGHTS[5:0]);
endmodule
