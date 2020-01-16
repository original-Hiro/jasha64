module CarryAheadAdder4(
    input logic [3:0] a,
    input logic [3:0] b,
    input logic c0,
    output logic [3:0] s,
    output logic ovf
);
    logic [3:0] p, g, c;
    integer i;
    always_comb
        for (i = 0; i < 4; i = i+1)
        begin
            p[i] =  a[i] ^ b[i]; g[i] = a[i] & b[i]; s[i] = p[i] ^ c[i];
        end
    assign c[0] = c0;
    assign c[1] = g[0] | (p[0] & c0);
    assign c[2] = g[1] | (p[1] & g[0]) | (p[1] & p[0] & c[0]);
    assign c[3] = g[2] | (p[2] & g[1]) | (p[2] & p[1] & g[0]) | (p[2] & p[1] & p[0] & c[0]);
    assign ovf = g[3] | (p[3] & c[3]);
endmodule
