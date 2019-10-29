module x7seg(
    input  logic [15:0] x,
    input  logic        clk,
    input  logic        clr,
    output logic [6:0] a2g,
    output logic [3:0] an,
    output logic       dp ); 
    
    logic [1:0] s;
    logic [3:0] digit;
    logic [3:0] aen;
    logic [19:0] clkdiv;
    
    assign dp = 1;           // DP off
    assign s = clkdiv[19:18];// count every 10.4ms        
    assign aen = 4'b1111;    // enable all digits
    
    //4位 4选1 MUX
    always_comb
    case(s)
        0:digit = x[3:0];
        1:digit = x[7:4];
        2:digit = x[11:8];
        3:digit = x[15:12];
        default: digit = x[3:0];
    endcase
    
    //Digit select: ancode
    always_comb
    begin
       an = 4'b1111;
       if(aen[s] == 1)
           an[s] = 0;
    end
    
    // 时钟分频器
    always @(posedge clk or posedge clr)
    begin
      if(clr == 1)
        clkdiv <=0;
      else
        clkdiv <= clkdiv + 1;
    end
    
    //实例化 7段数码管
    Hex7Seg s7(.data(digit), .a2g(a2g));    
endmodule