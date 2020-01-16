module Adder4(
    input logic [3:0] a,
    input logic [3:0] b,
    input logic c0,
    output logic [3:0] s,
    output logic cf //最高位上产生的进位
    //注：两个n位数相加产生了n+1位的运算结果就是溢出
    //对无符号数，溢出等价于最高位产生进位，所以上面的cf同时也是溢出指示变量
    //对有符号数，则检测最高位（符号位）和第二位（数值的最高位）产生的进位是否相等，若不等即说明发生了溢出
);
    logic c1, c2, c3;
    FullAdder(a[0], b[0], c0, s[0], c1); FullAdder(a[1], b[1], c1, s[1], c2);
    FullAdder(a[2], b[2], c2, s[2], c3); FullAdder(a[3], b[3], c3, s[3], cf);
endmodule
