module clkdiv(
    input logic mclk,
    input logic clr,
    output logic clk6000,
    output logic clk190,
    output logic clk1_4hz
);
    logic [24:0]q;
    always_ff @ (posedge mclk, posedge clr)
        if (clr == 1) q <= 0;
        else q <= q + 1;
    
    assign clk6000 = q[13]; //6000hz 
    assign clk190 = q[18]; //190hz 
    assign clk1_4hz = q[24];         
endmodule
