module Traffic2Top(
    input logic CLK100MHZ,
    input logic BTNC,
    input logic [0:0] SW,
    output logic [5:0] LIGHTS
    );
    logic clk1, st, ts, tl;
    clkdiv Cd(CLK100MHZ, BTNC, clk1);
    TimeCounter Tc(st, clk1, ts, tl);
    Traffic2 Ma(clk1, BTNC, SW[0], ts, tl, st, LIGHTS);
endmodule
