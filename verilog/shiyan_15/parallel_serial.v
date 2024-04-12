`timescale 1ns / 1ps

module parallel_serial(
clk, reset, en, data_i, data_o,dout/*,clk_real*/
    );
input clk, reset,en;
input [7:0] data_i;
output  data_o,dout;
//input clk_real;

reg [7:0]  data_buf;

	localparam N = 3; //使用低16位对50Mhz的时钟进行分频(50MHZ/2^16)
	reg [N-1:0] regN; //高两位作为控制信号，低16位为计数器，对时钟进行分频
	
	
	/*reg flag;
    always @ (posedge clk_real) 
        begin
            flag <=clk;
        end 
*/
	
	
	
	
    always@(posedge clk, posedge reset)
	begin
		if(reset)                    //FPGA板上配有 5 个按键，当按键按下时，表示 FPGA 的相应输入脚为高电平。所以平时的状态为低电平，即按键是未按下的  “弹起”  状态。
			regN <= 0;
		else
			regN <= regN + 1;
	end
	
always@(posedge clk or negedge reset)
if(reset)
data_buf <= 8'b0;
else if(en)                    
/*当en=0时，regN只能计数，不能执行以下传输代码，即不能改变data_buf的值了,不能再往seq_det_moore中传入下一个data_o了，
但是seq_det_moore还是会随着clk的进行，而继续检索1101序列，此时data_o的值是之前传入的值，不变。
只有在en=1后的下一次posedge clk时，才可以继续传输值*/
begin
case(regN[N-1:N-3])
3'b0: data_buf <= data_i[7:0];
3'b1: data_buf <= {data_i[6:0],data_i[7]};
3'd2: data_buf <= {data_i[5:0],data_i[7:6]};
3'd3: data_buf <= {data_i[4:0],data_i[7:5]};
3'd4: data_buf <= {data_i[3:0],data_i[7:4]};
3'd5: data_buf <= {data_i[2:0],data_i[7:3]};
3'd6: data_buf <= {data_i[1:0],data_i[7:2]};
3'd7: data_buf <= {data_i[0],data_i[7:1]};
default: data_buf <= data_i[7:0];
endcase
end


assign data_o = data_buf[7];

seq_det_moore u1(
    .clk(clk),
    .reset(reset),
    .din(data_o),//每按一次模拟 clk 的按键便传入一个开关的值
    .dout(dout)
    );

endmodule
