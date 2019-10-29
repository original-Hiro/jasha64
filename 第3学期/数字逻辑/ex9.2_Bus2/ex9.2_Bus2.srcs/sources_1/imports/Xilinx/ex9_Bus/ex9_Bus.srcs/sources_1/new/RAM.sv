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
        if (clr)
            begin
                mem[15] <= '0; mem[14] <= '0; mem[13] <= '0; mem[12] <= '0;
                mem[11] <= '0; mem[10] <= '0; mem[9] <= '0; mem[8] <= '0;
                mem[7] <= '0; mem[6] <= '0; mem[5] <= '0; mem[4] <= '0;
                mem[3] <= '0; mem[2] <= '0; mem[1] <= '0; mem[0] <= '0;
            end
        else if (wen) mem[addr] <= Din;
    assign Qout = mem[addr];
endmodule
