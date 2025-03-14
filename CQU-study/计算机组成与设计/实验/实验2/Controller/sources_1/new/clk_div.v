`timescale 1ns / 1ps
/*时钟分频模块：将100MHz的频率降为1hz
10^8(10)=0101_1111_0101_1110_0001_0000_0000(2)，约为2^27，即需要27位存储
注意：clk_division：0-1-0才是一个周期，因此第26位变化即可
    此模块不应加入rst
*/
module clk_div(
    input clk,
    output clk_division
);
    reg[27:0] cnt=0;
    reg division=0;
    assign clk_division=division;  
    always@(posedge clk)begin
        if(cnt==50000000-1)begin
        division<=~division;
        cnt<=0;
        end
        else
        cnt=cnt+1;
    end
    
endmodule
