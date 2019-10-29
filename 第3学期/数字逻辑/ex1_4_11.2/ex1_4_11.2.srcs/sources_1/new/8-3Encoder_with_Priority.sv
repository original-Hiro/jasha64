module Encoder83_with_Priority(input logic[7:0] in, output logic[2:0] o, output logic dp);
    always_comb
        casez (in)
            8'b1???_????: o = 3'b111;
            8'b01??_????: o = 3'b110;
            8'b001?_????: o = 3'b101;
            8'b0001_????: o = 3'b100;
            8'b0000_1???: o = 3'b011;
            8'b0000_01??: o = 3'b010;
            8'b0000_001?: o = 3'b001;
            8'b0000_0001: o = 3'b000;
        endcase
    assign dp = ~|in;
endmodule
