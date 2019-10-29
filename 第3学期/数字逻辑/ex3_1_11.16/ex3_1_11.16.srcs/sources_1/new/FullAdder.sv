module FullAdder(
    input logic a,
    input logic b,
    input logic cin,
    output logic s,
    output logic cout
);
    logic not_a, not_b, not_c;
    not(not_a, a); not(not_b, b); not(not_c, cin);
    logic sc[3:0];
    and3(sc[3], not_a, not_b, cin); and3(sc[2], not_a, b, not_c);
    and3(sc[1], a, not_b, not_c); and3(sc[0], a, b, cin);
    or4(s, sc[3], sc[2], sc[1], sc[0]);
    logic And[2:0];
    and(And[2], a, b); and(And[1], b, cin); and(And[0], cin, a);
    or3(cout, And[2], And[1], And[0]);
endmodule

module and3(output logic d, input logic a, input logic b, input logic c);
    logic ab;
    and(ab, a, b); and(d, ab, c);
endmodule

module or3(output logic d, input logic a, input logic b, input logic c);
    logic ab;
    or(ab, a, b); or(d, ab, c);
endmodule

module or4(output logic e, input logic a, input logic b, input logic c, input logic d);
    logic ab, cd;
    or(ab, a, b); or(cd, c, d); or(e, ab, cd);
endmodule
