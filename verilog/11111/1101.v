
`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/23 12:42:19
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
	input  clk,
    input rst,
    input    key,                      			
	output   clk_in,
	input en,
    input [7:0] data_in,
    output  data,dout
    );
        reg      pre_key;               
        reg      cur_key;                    
        wire     edge_key;                   
        always @(posedge clk  or  negedge rst)
          begin
             if (rst) begin
                 cur_key <=1'b1;               
                 pre_key <= 1'b1;
             end
             else begin
                 cur_key <= key;                    
                 pre_key <= cur_key;            
             end    
           end
        assign  edge_key = pre_key & (~cur_key);
        reg	[17:0]	  cnt;                      
        always @(posedge clk or negedge rst)
           begin
             if(rst)
                cnt <= 18'h0;
             else if(edge_key)
                cnt <= 18'h0;
             else
                cnt <= cnt + 1'h1;
             end  
        reg      pre_key_2;              
        reg       cur_key_2;                    
  
        always @(posedge clk  or  negedge rst)
          begin
             if (rst) 
                 cur_key_2 <= 1'b1;                
             else if (cnt==18'h3ffff)
                 cur_key_2 <= key;  
          end
       always @(posedge clk  or  negedge rst)
          begin
             if (rst)
                 pre_key_2 <=1'b1;
             else                   
                 pre_key_2 <= cur_key_2;             
         end      
       assign  clk_in = pre_key_2 & (~cur_key_2);     
  
    parallel_to_serial u1(
.clk(clk_in), .reset(rst), .en(en), .data_in(data_in), .data(data),.dout(dout)
    );
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/22 18:46:11
// Design Name: 
// Module Name: parallel_to_serial
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


module parallel_to_serial(
input clk, reset,en,
input [7:0] data_in,
output  data,dout
);
    reg [7:0]  data_reg;
	reg [2:0] tmp; 
    always@(posedge clk, posedge reset)
	begin
		if(reset)                   
			tmp <= 0;
		else
			tmp <= tmp + 1;
	end
always@(posedge clk or negedge reset)
if(reset)
data_reg <= 8'b0;
else if(en)                    
begin
case(tmp)
3'b0: data_reg <= data_in[7:0];
3'b1: data_reg <= {data_in[6:0],data_in[7]};
3'd2: data_reg <= {data_in[5:0],data_in[7:6]};
3'd3: data_reg <= {data_in[4:0],data_in[7:5]};
3'd4: data_reg <= {data_in[3:0],data_in[7:4]};
3'd5: data_reg <= {data_in[2:0],data_in[7:3]};
3'd6: data_reg <= {data_in[1:0],data_in[7:2]};
3'd7: data_reg <= {data_in[0],data_in[7:1]};
default: data_reg <= data_in[7:0];
endcase
end
assign data = data_reg[7];
moore_state_1101 u1(
    .clk(clk),
    .reset(reset),
    .din(data),
    .dout(dout)
    );
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/22 19:05:47
// Design Name: 
// Module Name: moore_state_1101
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


module moore_state_1101(
    input clk,
    input reset,
    input din,
    output reg dout
    );
    localparam [2:0] 
    s0 = 3'b000,
    s1 = 3'b001,
    s2 = 3'b010,
    s3 = 3'b011,
    s4 = 3'b100; 
    reg [2:0] state,next_state;
    always @(posedge clk, posedge reset)
    begin
        if(reset)            
            state <= s0;
        else
            state <= next_state;
    end
    always @ *
    begin
        case(state)
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
set_property IOSTANDARD LVCMOS33 [get_ports {data_in[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {data_in[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {data_in[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {data_in[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {data_in[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {data_in[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {data_in[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {data_in[0]}]
set_property PACKAGE_PIN W13 [get_ports {data_in[7]}]
set_property PACKAGE_PIN W14 [get_ports {data_in[6]}]
set_property PACKAGE_PIN V15 [get_ports {data_in[5]}]
set_property PACKAGE_PIN W15 [get_ports {data_in[4]}]
set_property PACKAGE_PIN W17 [get_ports {data_in[3]}]
set_property PACKAGE_PIN W16 [get_ports {data_in[2]}]
set_property PACKAGE_PIN V16 [get_ports {data_in[1]}]
set_property PACKAGE_PIN V17 [get_ports {data_in[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports clk]
set_property IOSTANDARD LVCMOS33 [get_ports data]
set_property IOSTANDARD LVCMOS33 [get_ports dout]
set_property IOSTANDARD LVCMOS33 [get_ports en]

set_property PACKAGE_PIN R2 [get_ports en]

set_property PACKAGE_PIN E19 [get_ports data]
set_property PACKAGE_PIN U16 [get_ports dout]

set_property IOSTANDARD  LVCMOS33 [get_ports key]
set_property IOSTANDARD  LVCMOS33 [get_ports clk_in]
set_property PACKAGE_PIN W5 [get_ports clk]
set_property IOSTANDARD LVCMOS33 [get_ports rst]
set_property PACKAGE_PIN U18 [get_ports rst]
set_property PACKAGE_PIN T17 [get_ports key]
set_property PACKAGE_PIN L1 [get_ports clk_in]

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/22 19:32:07
// Design Name: 
// Module Name: moore_state_1101_tb
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


module parallel_to_serial_tb();
	reg clk,reset,en;
	wire data;
	wire dout;
	reg [7:0] data_in;
   always begin
           #5 clk = ~clk;
   end  
				
	initial begin
    clk   = 0;
	reset = 1'b1;


	 @(posedge clk)   reset = 1'b0;
     en=1'b1;
     data_in = 8'b11010001;
	end
 
  parallel_to_serial u1(
.clk(clk), .reset(reset), .en(en), .data_in(data_in), .data(data) , .dout(dout)
    );
 
 
endmodule

