module _74377 (
    input logic clk,
    input logic clr,
    input logic en_b,
    input logic [3:0] D,
    output logic [3:0] Q);
    always_ff @ (posedge clk, posedge clr) //根据真值表，clr为1、clk为X时执行清零，可以判断是异步清零
        if (clr)  Q <= '0;
        else if (~en_b) Q <= D;
endmodule
