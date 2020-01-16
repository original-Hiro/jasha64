module Encoder83(input[7:0] in, output[2:0] o, output dp);
    assign o[2] = in[4] + in[5] + in[6] + in[7];
    assign o[1] = in[2] + in[3] + in[6] + in[7];
    assign o[0] = in[1] + in[3] + in[5] + in[7];
    assign dp = ~|in;
endmodule
