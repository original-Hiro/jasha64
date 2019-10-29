module clock_pulse(
    input logic clk1,
    input logic clr,
    output logic _5s,
    output logic _10s
    );
    parameter TS = 5, TL = 10;
    logic [5:0] cnt;
    always_ff @ (posedge clk1, posedge clr)
        if (clr == 1) begin cnt <= 0; _5s <= 0; _10s <= 0; end
        else if (cnt < TL-1) cnt <= cnt+1;
        else if (cnt == TL-1) begin cnt <= TL; _10s <= 1; end
        else if (cnt == TL) begin cnt <= TL+1; _10s <= 0; end
        else if (cnt < TS+TL-1) cnt <= cnt+1; 
        else if (cnt == TS+TL-1) begin cnt <= TS+TL; _5s <= 1; end
        else begin cnt <= 0; _5s <= 0; end
endmodule
