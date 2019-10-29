module BusTop(
    input logic CLK100MHZ,
    input logic BTNC,
    input logic [14:0] SW,
    output logic [15:0] LED);
    
    logic clk4;
    clkdiv U0(CLK100MHZ, BTNC, clk4);
    
    //logic yout[3:0], y2o[3:0], q1[3:0], q2[3:0], q3[3:0];
    logic [3:0] yout;
    logic [3:0] y2o;
    logic [3:0] q1;
    logic [3:0] q2;
    logic [3:0] q3;
    _74377 U1(clk4, BTNC, SW[7], y2o, q1);
    _74377 U2(clk4, BTNC, SW[6], yout, q2);
    _74377 U3(clk4, BTNC, SW[5], yout, q3);
    //logic q4[3:0];
    logic [3:0] q4;
    RAM U4(clk4, BTNC, SW[0], SW[4:1], yout, q4);
    
    assign LED[3:0] = q2;
    assign LED[7:4] = q3;
    assign LED[11:8] = q1;
    assign LED[15:12] = q4;
    /*
    always_comb
        begin
            LED[0] = q2[0]; LED[1] = q2[1]; LED[2] = q2[2]; LED[3] = q2[3];
            LED[4] = q3[0]; LED[5] = q3[1]; LED[6] = q3[2]; LED[7] = q3[3];
            LED[8] = q1[0]; LED[9] = q1[1]; LED[10] = q1[2]; LED[11] = q1[3];
            LED[12] = q4[0]; LED[13] = q4[1]; LED[14] = q4[2]; LED[15] = q4[3];
        end
    */
    
    Mux#(1) U5({yout, SW[11:8]}, SW[12], y2o);
    Mux#(2) U6({q4, q3, q2, q1}, SW[14:13], yout);
    
endmodule
/*
instruction: 
初始化：SW[7] = SW[6] = SW[5] = 1，SW[0] = 0
先通过U5输入x（值自定）：在SW[11:8]上设定x的值，然后设定SW[12]=0
打开U1的en，x会自动通过U1到达U6：设定SW[7]=0；此时LED[11:8]==x；完成后设定SW[7]=1
在U6处指定将q1赋给U2：设定SW[14:13]=0，SW[6]=0；此时LED[3:0]==x；完成后设定SW[6]=1
同样将y从U5→U1→U6→U3：
 在SW[11:8]上设定y的值，然后设定SW[12]=0
 设定SW[7]=0；此时LED[11:8]==y；完成后设定SW[7]=1
 设定SW[14:13]=0，SW[5]=0；此时LED[7:4]==y；完成后设定SW[5]=1
然后x从U2→U6→U4：设定SW[14:13]=1，SW[4:1]=0，SW[0]=1；此时LED[15:12]==x；完成后设定SW[0]=0
y从U3→U6→U4（存入不同地址）：设定SW[14:13]=2，SW[4:1]=1（不同地址），SW[0]=1；此时LED[15:12]==y；完成后设定SW[0]=0
然后x从U4→U6→U3：设定SW[4:1]=0；此时LED[15:12]==x；设定SW[14:13]=3，SW[5]=0；此时LED[7:4]==x；完成后设定SW[5]=1
y从U4→U6→U2：设定SW[4:1]=1；此时LED[15:12]==y；设定SW[14:13]=3，SW[6]=0；此时LED[3:0]==y；完成后设定SW[6]=1
*/
