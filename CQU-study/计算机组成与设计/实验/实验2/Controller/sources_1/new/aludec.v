`timescale 1ns / 1ps
/* ALU decoder：一些指令需要ALU进行运算，输入funct和aluop，输出alu control
    lw：aluop(00)——>alu control(010)
    sw：aluop(00)-->alu control(010)
    addi：aluop(00)-->alu control(010)
    beq:aluop(01)-->alu control(110)
    add：aluop(10)、funct(100000)-->alu control(010)
    sub：aluop(10)、funct(100010)-->alu control(110)
    and：aluop(10)、funct(100100)-->alu control(000)
    or：aluop(10)、funct(100101)-->alu control(001)
    slt：aluop(10)、funct(101010)-->alu control(111)
*/

module aludec(
    input wire[1:0] aluop,
    input wire[5:0] funct,
    output reg [2:0] aluctrl
);
    always@(*)begin
        case(aluop)
            2'b00:aluctrl=010;              //lw、sw
            2'b01:aluctrl=110;              //beq
            2'b10:begin                     //R型指令
                case(funct)
                    6'b100000:aluctrl=010;  //add
                    6'b100010:aluctrl=110;  //sub
                    6'b100100:aluctrl=000;  //and
                    6'b100101:aluctrl=001;  //or
                    6'b101010:aluctrl=111;  //slt
                endcase
            end
            default:aluctrl='b0;            
        endcase
    end
endmodule
