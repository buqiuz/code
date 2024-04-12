`timescale 1ns / 1ps
module sequence(
    input in,
    input clk,
    input reset,
    output check
);

    //同步置位---reset
    //实现1101序列的检测器
    
    //定义状态
    parameter idle=0, bit1=1, bit2 =2, bit3=3, bit4=4;
    reg [2:0] state, next_state;
    
    //组合逻辑实现转态的转变
    always @(*)
        begin
            case(state)
                idle: next_state = in ? bit1 : idle;
                bit1: next_state = in ? bit2 : idle;
                bit2: next_state = in ? bit2 : bit3;
                bit3: next_state = in ? bit4 : idle;
                bit4: next_state = in ? bit2 : idle;
                default: next_state = idle;
            endcase
        end
        
    //时序逻辑
    always @(posedge clk)
        begin
            if(reset)
                state <= idle;
            else
                state <= next_state;
        end
        
    //组合逻辑输出
    assign check = (state == bit4);
endmodule

