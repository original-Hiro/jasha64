module SevenSegmentDisplay(
    input logic [15:0] in,
    input logic clk,
    output logic [7:0] an,
    output logic dp,
    output logic [6:0] out
);
    //小数点关闭
    assign dp = 1;
    
    //七段数码管显示内容
    logic [3:0] digit;
    logic [6:0] outc;
    always_comb
    case (digit)
        'h0: outc = 7'b0111111;
        'h1: outc = 7'b0000110;
        'h2: outc = 7'b1011011;
        'h3: outc = 7'b1001111;
        'h4: outc = 7'b1100110;
        'h5: outc = 7'b1101101;
        'h6: outc = 7'b1111101;
        'h7: outc = 7'b0000111;
        'h8: outc = 7'b1111111;
        'h9: outc = 7'b1100111;
        'hA: outc = 7'b1110111;
        'hB: outc = 7'b1111100;
        'hC: outc = 7'b0111001;
        'hD: outc = 7'b1011110;
        'hE: outc = 7'b1111001;
        'hF: outc = 7'b1110001;
    endcase
    assign out = ~outc;
    
    //时钟分频器
    logic[19:0] clkdiv;
    always @ (posedge clk)
        clkdiv <= clkdiv + 1;
    
    //分时点亮数码管
    logic[1:0] s;
    assign s = clkdiv[19:18]; //选择95KHz的分频，每隔10.4ms选择下一个数码管
    always_comb
    begin
        an = 8'b1111_1111; an[s] = 0;
        case (s)
            0: digit = in[3:0];
            1: digit = in[7:4];
            2: digit = in[11:8];
            3: digit = in[15:12];
        endcase
    end
        
endmodule
//注：老师提供的原版文件中有clr这个变量用于复位时钟，在这个实验中把它去掉也无影响
//但在以后更复杂的时序电路设计中，这个变量（和reset变量）经常是必须使用的
