module DigitalClock_Top(
    input  logic CLK100MHZ,
    input  logic [2:0]SW,
    output logic [6:0]A2G,
    output logic [7:0]AN,
    output logic DP);
    
    // 产生1秒
    logic clk, clk4, clk190, clk6000, _1s;
    clkdiv CD(.mclk(CLK100MHZ), .clr(SW[0]), .clk6000(clk6000), .clk190(clk190), .clk1_4hz(clk4));
    OneSecond U1(.clk(CLK100MHZ), .clr(SW[0]), ._1s(_1s));
    always_comb
        case (SW[2:1])
        0: clk = clk4;
        1: clk = clk190;
        2: clk = clk6000;
        3: clk = _1s;
        endcase
    
    // 秒
    logic [7:0] s_count;
    logic s_out;   
    logic [9:0] s_BCD; 
    TimeCounter S1(.clk(clk), .clr(SW[0]), .time_in(clk), 
                   .time_counter(s_count), .time_out(s_out));
    Bin2BCD8bit S2(.b(s_count), .p(s_BCD));               
    // 分钟
    logic [7:0] m_count;
    logic m_out;
    logic [9:0] m_BCD; 
    TimeCounter M1(.clk(clk), .clr(SW[0]), .time_in(s_out), 
                   .time_counter(m_count), .time_out(m_out));
    Bin2BCD8bit M2(.b(m_count), .p(m_BCD));
    // 小时
    logic [7:0] h_count;
    logic h_out;
    logic [9:0] h_BCD;
    TimeCounter #(24) H1(.clk(clk), .clr(SW[0]), .time_in(m_out),
                        .time_counter(h_count), .time_out(h_out));
    Bin2BCD8bit H2(.b(h_count), .p(h_BCD));
    
    // 输出 23:59:59                  
    logic [31:0] x;  
    assign x = {8'b0000_0000, h_BCD[7:0], m_BCD[7:0], s_BCD[7:0]};
    // 显示
    SevenSegmentDisplay X7(.clk(CLK100MHZ), .clr(SW[0]), .in(x),
             .out(A2G), .an(AN), .dp(DP)) ;   
endmodule
