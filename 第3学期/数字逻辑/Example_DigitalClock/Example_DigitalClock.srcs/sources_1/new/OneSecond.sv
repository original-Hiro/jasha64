`timescale 1ns / 1ps
// 100MHz时钟产生1秒输出
module OneSecond(
    input  logic clk,
    input  logic clr,
    output logic OneSecond );//reg
    
    parameter N = 99_999999;
    logic [31:0] count; //reg
    
    always @(posedge clk, posedge clr)
        if(clr==1)  count <= 0;
        else
        begin
            OneSecond <= 0;
            if(count < N) count <= count + 1;
            else
            begin
                count <= 0;
                OneSecond <= 1;
            end
        end
endmodule