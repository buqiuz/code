`timescale 1ns / 1ps
 
 
module seq_det_moore(
    input clk,
    input reset,
    input din,
    output reg dout
    );
    //状态声明
    localparam [2:0]
    s0 = 3'b000,
    s1 = 3'b001,
    s2 = 3'b010,
    s3 = 3'b011,
    s4 = 3'b100;
    
    reg [2:0] current_state,next_state;
    
    always @(posedge clk, posedge reset)
    begin
        if(reset)            //FPGA板上配有 5 个按键，当按键按下时，表示 FPGA 的相应输入脚为高电平。所以平时的状态为低电平，即按键是未按下的  "弹起"  状态。
            current_state <= s0;
        else
            current_state <= next_state;
    end
    
    always @ *
    begin
        case(current_state)
        s0:
            if(din == 1'b1) next_state = s1;
            else next_state = s0;
        s1:
            if(din == 1'b1) next_state = s2;
            else next_state = s0;
        s2:
            if(din == 1'b0) next_state = s3;
            else next_state = s2;
        s3:
            if(din == 1'b1) next_state = s4;
            else next_state = s0;
        s4:
            if(din == 1'b1) next_state = s1;
            else next_state = s0;
        default: next_state = s0;
        
        endcase
    
    end
    
    always @*
    begin
        if(next_state == s4) dout = 1;
        else dout = 0;
    end
    
    
endmodule

