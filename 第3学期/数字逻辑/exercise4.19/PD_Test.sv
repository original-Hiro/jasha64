module PD_Test();
    logic[3:0] a;
    logic p, d;
    PD pd(a, p, d); //仿真文件必须给模块命名
    logic[4:0] b;
    initial
        for (b = 0; b < 16; b = b+1) #10 a = b; //因为a只有4位，所以a == 15时 a = a+1就会变为0，从而死循环
endmodule
