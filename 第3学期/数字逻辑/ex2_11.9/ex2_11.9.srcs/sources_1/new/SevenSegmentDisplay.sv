module SevenSegmentDisplay(
    input [3:0] in,
    output [7:0] an,
    output dp,
    output reg [6:0] out
);
    assign an = 8'b01111111;
    assign dp = 1;
    reg [6:0] outc;
    always_comb
    case (in)
        'h0: outc = 7'b0111111;
        'h1: outc = 7'b0000110;
        'h2: outc = 7'b1011011;
        'h3: outc = 7'b1001111;
        'h4: outc = 7'b1100110;
        'h5: outc = 7'b1101101;
        'h6: outc = 7'b1111101;
        'h7: outc = 7'b0000111;
        'h8: outc = 7'b1111111;
        'h9: outc = 7'b1100111;
        'hA: outc = 7'b1110111;
        'hB: outc = 7'b1111100;
        'hC: outc = 7'b0111001;
        'hD: outc = 7'b1011110;
        'hE: outc = 7'b1111001;
        'hF: outc = 7'b1110001;
        //default: outc = 7'bxxxxxxx; //±ÜÃâÉú³ÉËø´æÆ÷
    endcase
    assign out = ~outc;
    
endmodule
