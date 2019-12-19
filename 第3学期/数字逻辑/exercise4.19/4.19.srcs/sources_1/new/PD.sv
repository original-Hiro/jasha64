module PD(
    input logic[3:0] a,
    output logic p,
    output logic d
);
    always_comb
    begin
        if (a % 3 == 0) d = 1;
        else d = 0;
        if (a == 2 || a == 3 || a == 5 || a == 7 || a == 11 || a == 13) p = 1;
        else p = 0;
    end
endmodule
