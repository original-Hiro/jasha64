module Hex7Seg(
    input  logic [3:0] data,
    output logic [6:0] a2g); 
    // A2G format {g, f, e, d, c, b, a} 
    always_comb
    case (data) //   {g,f,e,d,c,b,a}
        'h0: a2g = 7'b1_0_0_0_0_0_0; 
        'h1: a2g = 7'b1_1_1_1_0_0_1; 
        'h2: a2g = 7'b0_1_0_0_1_0_0; 
        'h3: a2g = 7'b0_1_1_0_0_0_0; 
        'h4: a2g = 7'b0_0_1_1_0_0_1; 
        'h5: a2g = 7'b0_0_1_0_0_1_0; 
        'h6: a2g = 7'b0_0_0_0_0_1_0; 
        'h7: a2g = 7'b1_1_1_1_0_0_0; 
        'h8: a2g = 7'b0_0_0_0_0_0_0; 
        'h9: a2g = 7'b0_0_1_0_0_0_0; 
    default: a2g = 7'b1_0_0_0_0_0_0; //0
    endcase 
endmodule