//4bit * 2^4 bit
module RAM(
    input logic clk,
    input logic clr,
    input logic wen,
    input logic [3:0] addr,
    input logic [3:0] Din,
    output logic [3:0] Qout
    );
    logic [3:0] mem[15:0];
    always_ff @ (posedge clk)
        if (wen) mem[addr] <= Din;
    assign Qout = mem[addr];
endmodule
