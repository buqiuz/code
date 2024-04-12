`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/03/22 19:23:11
// Design Name: 
// Module Name: alu
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module alu(
    input [7:0] num1,
    input [31:0] num2,
    input [2:0] op,
    output reg[31:0] out
    );
    always @(*) begin
        case (op)
            3'b000: out={16'b0,num1}+num2;
            3'b001: out={16'b0,num1}-num2;
            3'b010: out={16'b0,num1}&num2;
            3'b011: out={16'b0,num1}|num2;
            3'b100: out=~{16'b0,num1};
            3'b101: if ({16'b0,num1}<num2) out=1; else out=0;
            
            default: out=0;
        endcase
    end
endmodule
