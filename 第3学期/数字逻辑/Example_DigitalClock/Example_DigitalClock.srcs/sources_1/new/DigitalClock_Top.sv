module DigitalClock_Top(
    input  logic CLK100MHZ,
    input  logic BTNC,
    output logic [6:0] A2G,
    output logic [3:0] AN,
    output logic       DP);
    // 产生1秒
    logic _1s;
    OneSecond U1(.clk(CLK100MHZ), .clr(BTNC), .OneSecond(_1s));
    // 秒
    logic [7:0] s_count;
    logic s_out;   
    logic [9:0] s_BCD; 
    TimeCounter S1(.clk(CLK100MHZ), .clr(BTNC), .time_in(_1s), 
                   .time_counter(s_count), .time_out(s_out));
    Bin2BCD8bit S2(.b(s_count), .p(s_BCD));               
    // 分钟
    logic [7:0] m_count;
    logic m_out;
    logic [9:0] m_BCD; 
    TimeCounter M1(.clk(CLK100MHZ), .clr(BTNC), .time_in(s_out), 
                   .time_counter(m_count), .time_out(m_out));
    Bin2BCD8bit M2(.b(m_count), .p(m_BCD));
    // 输出 59:58                  
    logic [15:0] x;  
    assign x = {m_BCD[7:0], s_BCD[7:0]};
    // 显示
    x7seg X7(.x(x), .clk(CLK100MHZ), .clr(BTNC),
             .a2g(A2G), .an(AN), .dp(DP)) ;                  
endmodule