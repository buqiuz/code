`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/24 20:16:45
// Design Name: 
// Module Name: hexseg5_3
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


module hexseg5_3 (
    input clk,
    input [2:0] a,
    input [2:0] b,
    input [2:0] c,
    input [2:0] d,
    output reg [6:0] segs0,
    output reg [6:0] segs1,
    output reg [6:0] segs2,
    output reg [6:0] segs3

);  
    reg [1:0] digit=2'b00;
    reg [19:0] count=0;
    reg clk_div=0;
    always @(posedge clk) begin
        count=count+1;
        if (count[19]==1) begin
            count=0;
            clk_div=~clk_div;   
        end
    end
    always @(*) begin
        if (digit==2'b00) begin
           case (a)
                4'h0: segs0=7'b000_0001;
                4'h1: segs0=7'b100_1111;
                4'h2: segs0=7'b001_0010;
                4'h3: segs0=7'b000_0110;
                4'h4: segs0=7'b100_1100;
                4'h5: segs0=7'b010_0100;
                4'h6: segs0=7'b010_0000;
                4'h7: segs0=7'b000_1111;
                default: 
                    segs0=7'b111_1111;
            endcase
        end
        if (digit==2'b01) begin
           case (b)
                4'h0: segs1=7'b000_0001;
                4'h1: segs1=7'b100_1111;
                4'h2: segs1=7'b001_0010;
                4'h3: segs1=7'b000_0110;
                4'h4: segs1=7'b100_1100;
                4'h5: segs1=7'b010_0100;
                4'h6: segs1=7'b010_0000;
                4'h7: segs1=7'b000_1111;
                default: 
                    segs1=7'b111_1111;
            endcase
        if (digit==2'b10) begin
           case (c)
                4'h0: segs2=7'b000_0001;
                4'h1: segs2=7'b100_1111;
                4'h2: segs2=7'b001_0010;
                4'h3: segs2=7'b000_0110;
                4'h4: segs2=7'b100_1100;
                4'h5: segs2=7'b010_0100;
                4'h6: segs2=7'b010_0000;
                4'h7: segs2=7'b000_1111;
                default: 
                    segs2=7'b111_1111;
            endcase
        end
        if (digit==2'b11) begin
           case (d)
                4'h0: segs3=7'b000_0001;
                4'h1: segs3=7'b100_1111;
                4'h2: segs3=7'b001_0010;
                4'h3: segs3=7'b000_0110;
                4'h4: segs3=7'b100_1100;
                4'h5: segs3=7'b010_0100;
                4'h6: segs3=7'b010_0000;
                4'h7: segs3=7'b000_1111;
                default: 
                    segs3=7'b111_1111;
            endcase
           
        end
    end

endmodule

