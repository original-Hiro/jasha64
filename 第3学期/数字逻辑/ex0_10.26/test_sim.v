`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/10/26 15:16:43
// Design Name: 
// Module Name: test_sim
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


module test_sim;

    reg[7:0] switches; //input type of simulation
    wire[7:0] leds; //output type of simulation
    test dut(.LED(leds), .SW(switches));
    
    initial
    begin
        for (integer i = 0; i < 255; i = i+2) #50 switches = i;
    end

endmodule
