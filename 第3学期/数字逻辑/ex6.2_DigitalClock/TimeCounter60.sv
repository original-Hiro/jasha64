`timescale 1ns / 1ps
// 计数器
module TimeCounter
    #(parameter N = 60)
   (input  logic clk,
    input  logic clr,
    input  logic time_in,     // 低位进位
    output logic [7:0] time_counter,// reg
    output logic time_out );  // 高位进位 reg
    
    always @(posedge clk, posedge clr)
        if(clr)     time_counter <= 0;
        else
        begin
            time_out <= 0;
            if(time_in==1) // 有低位进位时 ========
                if(time_counter<N-1) 
                    time_counter <= time_counter + 1;
                else
                begin
                    time_counter <= 0;
                    time_out <= 1;
                end
        end
endmodule
