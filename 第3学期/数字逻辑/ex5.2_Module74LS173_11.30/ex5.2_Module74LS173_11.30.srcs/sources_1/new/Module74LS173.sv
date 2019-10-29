module Module74LS173 (
    input logic clk,
    input logic clr,
    input logic[1:0] g,
    input logic[1:0] mn,
    input logic[3:0] D,
    output logic[3:0] out
);
    logic dis, en;
    logic[3:0] Q;
    assign dis = |mn; assign en = ~g[1] & ~g[0];
    always_ff @ (posedge clk, posedge clr) //根据真值表，clr为1、clk为X时执行清零，可以判断是异步清零
        if (clr) Q <= '0;
        else if (en) Q <= D;
    always_comb
        if (dis) out = 'z; //When either M or N (or both) is (are) high, the output is disabled to the high-impedance state 当输入阻断信号为真，输出高阻态（而非输出1）
        else out = Q;
endmodule
