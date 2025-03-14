`timescale 1ns / 1ps

module top_sim2();
    reg clk=0,rst=0;
    wire[31:0] IR;
    wire[2:0] aluctrl;
    wire memtoreg,memwrite,alusrc,regdst,regwrite,branch,jump;
    
    reg ena=1;
    reg[31:0] addr=0;
    IR_ROM gate3(clk,rst,ena,addr,IR);
    controller gate4(IR[31:26],IR[5:0],aluctrl,memtoreg,memwrite,alusrc,regdst,regwrite,branch,jump);
    
//    always #20 begin
//        clk<=~clk;
//        addr<=addr+0.5;
//    end
    initial begin
        #30 clk=1;addr=4;
        #30 clk=0;
        #30 clk=1;addr=8;
        #30 clk=0;
        #30 clk=1;addr=12;
        #30 clk=0;
        #30 clk=1;addr=16;
        #30 clk=0;
        #30 clk=1;addr=20;
        #30 clk=0;
        #30 clk=1;addr=24;
//        #30 clk=0;
//        #30 clk=1;addr=12;
//        #30 clk=0;
//        #30 clk=1;addr=13;
//        #30 clk=0;
//        #30 clk=1;addr=14;
//        #30 clk=0;
//        #30 clk=1;addr=15;
//        #30 clk=0;
//        #30 clk=1;addr=16;
//        #30 clk=0;
    end
    
    
endmodule
