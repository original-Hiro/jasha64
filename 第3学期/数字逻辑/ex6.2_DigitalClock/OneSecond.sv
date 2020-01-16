module OneSecond(
    input logic clk,
    input logic clr,
    output logic _1s
);
    parameter N = 99_999999; //clk is 100MHz
    logic [31:0] cnt;
    
    always_ff @ (posedge clk, posedge clr)
    if (clr == 1) cnt <= 0;
    else
    begin
        _1s <= 0;
        if (cnt < N) cnt <= cnt + 1;
        else
        begin
            cnt <= 0;
            _1s <= 1;
        end
    end
endmodule
