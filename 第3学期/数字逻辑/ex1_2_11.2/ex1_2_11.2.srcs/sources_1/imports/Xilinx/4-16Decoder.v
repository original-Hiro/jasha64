module Decoder4_16(output[15:0] o, input a, input b, input c, input d);
    wire[2:0] g1, g2;
    assign g1[0] = 1; assign g1[1] = d; assign g1[2] = d;
    assign g2[0] = d; assign g2[1] = 0; assign g2[2] = 0;
    Decoder38 d1(o[7:0], a, b, c, g1), d2(o[15:8], a, b, c, g2);
endmodule
