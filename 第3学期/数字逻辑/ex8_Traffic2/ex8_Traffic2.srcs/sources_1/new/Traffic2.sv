module Traffic2(
    input logic clk,
    input logic clr,
    input logic tr, //traffic detected
    input logic ts, //time short
    input logic tl, //time long
    output logic st, //start time counting
    output logic [5:0] lights //also the current state
    );
    parameter
               //F  H
              //RGBRGB
        HG = 6'b100010,
        HY = 6'b100110,
        FG = 6'b010100,
        FY = 6'b110100;
    always_ff @ (posedge clk, posedge clr)
        if (clr == 1) begin lights <= HG; st <= 1; end
        else
            begin
                st <= 0;
                case (lights)
                    HG: if (tl & tr) begin lights <= HY; st <= 1; end
                    HY: if (ts) begin lights <= FG; st <= 1; end
                    FG: if (tl | ~tr) begin lights <= FY; st <= 1; end
                    FY: if (ts) begin lights <= HG; st <= 1; end
                    default: lights <= HG;
                endcase
            end
endmodule
