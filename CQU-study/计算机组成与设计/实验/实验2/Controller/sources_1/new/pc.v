`timescale 1ns / 1ps
//pc模块：根据时钟信号计数，输出当前指令地址
//addr不赋初值仿真会出现问题，第一条指令会被吞掉
module pc(
    input clk,rst,
    output reg[31:0] addr=0,    
    output wire ena             
);
    reg [31:0] cnt=0;           
    assign ena=(addr<1024)?1:0; 
    always@(posedge clk)begin
        if(rst)begin
            cnt<=0;
            addr<=cnt;
        end
        else begin
           cnt<=cnt+4;
           addr<=cnt;
        end
    end
endmodule
