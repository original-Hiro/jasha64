module Decoder38(output[7:0] o, input a, input b, input c, input[2:0] g);
    wire g2, en;
    nor(g2, g[2], g[1]); and(en, g[0], g2);
    wire a_not, b_not, c_not;
    not(a_not, a); not(b_not, b); not(c_not, c);
    nand4(o[7], en, a, b, c); nand4(o[6], en, a_not, b, c); nand4(o[5], en, a, b_not, c); nand4(o[4], en, a_not, b_not, c);
    nand4(o[3], en, a, b, c_not); nand4(o[2], en, a_not, b, c_not); nand4(o[1], en, a, b_not, c_not); nand4(o[0], en, a_not, b_not, c_not);
endmodule

module nand4(output o, input a, input b, input c, input d);
    wire ab, cd;
    and(ab, a, b); and(cd, c, d); nand(o, ab, cd);
endmodule
