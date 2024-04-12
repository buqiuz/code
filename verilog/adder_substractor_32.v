`timescale 1ns / 1ps

module adder_substractor_32 (
	input [32:1]in1,
	input [32:1]in2,
	input add_sub,
	output Gm,
	output Pm,
	output	[32:1]sum,
    output c32,
    input                      clk,
    input                      rst_n
);
wire [32:1] in1_exp;
wire [32:1] in2_exp;
wire cin;
wire [32:1]sum_temp1;
wire [32:1]sum_temp2;

assign in1_exp = {in1};
assign in2_exp = add_sub? ~{in2}: {in2};       //做减法时，需要对in2进行补码运算
assign cin = add_sub;                          //对in2进行2的补码运算

// 因为对输入进行了扩位,所以WIDTH需要加1，在输出的时候会被截位，但对结果无影响
adder32 adder32(
    .A( in1_exp   ),
    .B( in2_exp   ),
    .c0( cin   ),
    .Gm(Gm),
    .Pm(Pm),
    .S( sum_temp1  ),
    .C32(c32),
    .clk(clk),
    .rst_n(rst_n)
);


adder32_carry_lookahead_unit adder32_carry_lookahead_unit_temp(
    .A( ~sum_temp1   ),
    .B(  0   ),
    .c0( 1'b1  ),
    .Gm( ),
    .Pm( ),
    .S( sum_temp2  ),
    .C32( )
);

assign sum = (add_sub&(~c32))? {sum_temp2}: {sum_temp1};       //做减法时，若结果为负数，需要对in2进行补码运算

endmodule
