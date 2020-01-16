module ALU(
    input logic[3:0] a,
    input logic[3:0] b,
    input logic cin,
    input logic[1:0] s,
    input logic m,
    output logic[3:0] c,
    output logic cf,
    output logic zf
);
    always_comb
    begin
        cf = 0;
        if (m == 0)
            case (s)
                2'b00: c = ~a;
                2'b01: c = a & b;
                2'b10: c = a | b;
                2'b11: c = a ^ b;
            endcase
        else begin
                casez (s)
                    2'b1?: {cf, c} = 5'bx_xxxx;
                    2'b00: {cf, c} = a + b + cin;
                    2'b01: {cf, c} = a - b - cin;
                endcase
            end
        if (c == 4'b0000) zf = 1;
        else zf = 0;
    end
endmodule
