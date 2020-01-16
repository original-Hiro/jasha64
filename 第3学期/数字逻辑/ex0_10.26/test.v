`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/26 14:10:02
// Design Name: 
// Module Name: test
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module test(
    input[7:0] SW,
    output[7:0] LED
    );
    assign LED[0] = ~SW[0];
    assign LED[1] = SW[1] & ~SW[2];
    assign LED[3] = SW[2] & SW[3];
    assign LED[2] = LED[1] | LED[3];
    assign LED[7:4] = SW[7:4];
endmodule
//此处的端口名与限定文件中保持一致，否则运行时会出问题
