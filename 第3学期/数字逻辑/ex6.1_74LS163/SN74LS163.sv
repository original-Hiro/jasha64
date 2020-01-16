module _74LS163(
    input logic Clear_b,
    input logic clk,
    input logic EP,
    input logic ET,
    input logic Load_b,
    input logic D0, D1, D2, D3,
    output logic Q0, Q1, Q2, Q3,
    output logic RCO
);
    logic [3:0] D;
    logic [3:0] Q;
    assign D = {D3, D2, D1, D0};
    
    always_ff @ (posedge clk)
    begin
        RCO <= 0;
        if (Clear_b == 0) Q <= 0;
        else if (Load_b == 0) Q <= D;
        else if (EP == 1 && ET == 1)
        begin
            if (Q == 14)
            begin
                Q <= Q + 1; RCO <= 1;
            end
            else Q <= Q + 1;
        end
    end
    
    assign Q3 = Q[3];
    assign Q2 = Q[2];
    assign Q1 = Q[1];
    assign Q0 = Q[0];
endmodule