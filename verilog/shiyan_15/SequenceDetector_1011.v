module SequenceDetector_1101(
	//input 
	clk,
	rst_n,
	in,
	//output
	out 
);
input clk,rst_n,in;
output reg out;
//parameter define
parameter
	S0 = 5'b00001,
	S1 = 5'b00010,
	S2 = 5'b00100,
	S3 = 5'b01000,
	S4 = 5'b10000;
 
//reg define
reg[4:0] current_state,next_state;
 
//first
always @(posedge clk or negedge rst_n)
	begin 
		if(!rst_n)
			current_state <= S0;
		else
			current_state <= next_state;
	end 
 
//second
always @(posedge clk   or  negedge rst_n)
	begin
	if(!rst_n)
		next_state = S0;
	else 
	begin
		case(current_state)
			S0:
				begin
					if(in == 1)
						next_state <= S1;
					else
						next_state <= S0;
				end 
			S1:
				begin
					if(in == 1)
						next_state <= S2;
					else
						next_state <= S0;
				end 
			S2:
				begin
					if(in == 1)
						next_state <= S2;
					else
						next_state <= S3;
				end 
			S3:
				begin
					if(in == 1)
						next_state <= S4;
					else
						next_state <= S0;			
				end 
			S4:
				begin
					if(in == 1)
						next_state <= S2;
					else
						next_state <= S0;			
				end 				
		endcase
		end 
	end 
//third
always @(current_state)
	begin
		case(current_state)
			S0:out = 0;
			S1:out = 0;
			S2:out = 0;
			S3:out = 0;
			S4:out = 1;
			
		endcase
	end 
	
endmodule