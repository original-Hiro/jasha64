module Traffic(
    input logic clk1,
    input logic _15s,
    input logic _45s,
    input logic clr,
    output logic [5:0] lights //输出交通灯状态
    );
    logic [1:0] state; //现态
    parameter S0 = 2'b00, S1 = 2'b01, S2 = 2'b10, S3 = 2'b11; //状态编码
    
    //自动机部分
    always_ff @ (posedge clk1, posedge clr)
        if (clr == 1) state <= S0;
        else
            case (state)
                S0: if (_45s) state <= S1;
                    else state <= S0;
                S1: if (_15s) state <= S2;
                    else state <= S1;
                S2: if (_45s) state <= S3;
                    else state <= S2;
                S3: if (_15s) state <= S0;
                    else state <= S3;
            endcase
    
    //组合输出部分
    always_comb           //NS  EW
        case (state)      //GBRGBR
            S0: lights = 6'b100001;
            S1: lights = 6'b101001;
            S2: lights = 6'b001100;
            S3: lights = 6'b001101;
        endcase
endmodule
