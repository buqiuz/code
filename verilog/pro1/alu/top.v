`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/03/22 19:22:56
// Design Name: 
// Module Name: top
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


module top(
    input [7:0] ins,
    input [2:0] op,
    input clk,
    input rst,
    output [6:0] seg,
    output [7:0] ans
    );
    wire [31:0] out;
    alu a1(ins,op,out);
    display d1(clk,rst,out,seg,ans);
endmodule
