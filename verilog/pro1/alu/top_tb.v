`timescale 1ns / 1ps

module top_tb;




  reg [7:0] ins;
  reg [2:0] op;
  reg clk=0, rst;

  wire [7:0]  ans;
  wire [6:0]  seg;

  // Instantiate the unit under test (UUT)
  top uut (
    .ins(ins),
    .op(op),
    .clk(clk),
    .rst(rst),
    .seg(seg),
    .ans(ans)
  );
  
   

  always 
  #5 clk=~clk;



  // Reset generation
  initial begin
    rst = 1;
    #10; // Reset for 100 ns
    rst = 0;
  end

  // Test vector generation
  initial begin
    
    // Test vectors
    ins = 8'b00000001;
    op = 3'b000;
    #100; // Wait for some time

    ins = 8'b00000010;
    op = 3'b001;
    #100; // Wait for some time
    
    ins = 8'b00000010;
    op = 3'b010;
    #100; // Wait for some time
    
    ins = 8'b00000010;
    op = 3'b011;
    #100; // Wait for some time
    
    ins = 8'b00000010;
    op = 3'b100;
    #100; // Wait for some time
    
    ins = 8'b00000010;
    op = 3'b101;
    #100; // Wait for some time
    

 
  end

endmodule
