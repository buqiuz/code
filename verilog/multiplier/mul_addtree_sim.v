module testbench;

  reg clk, rst_n, vld_in;
  reg [3:0] x, y;
  wire [7:0] p;
  wire vld_out;

  // Instantiate the multiplier module
  mul_addtree uut(
    .clk(clk),
    .rst_n(rst_n),
    .vld_in(vld_in),
    .x(x),
    .y(y),
    .p(p),
    .vld_out(vld_out)
  );

  // Clock generation
  always #5 clk = ~clk;

  // Initial values
  initial begin
    clk = 0;
    rst_n = 0;
    vld_in = 0;
    x = 4'b0;
    y = 4'b0;

    // Apply reset
    #10 rst_n = 1;

    // Test case 1
    #10 x = 4'b0010; y = 4'b0011; vld_in = 1;
    #10 vld_in = 0;

    // Test case 2
    #10 x = 4'b1101; y = 4'b0110; vld_in = 1;
    #10 vld_in = 0;

    // Add more test cases as needed

    #100 $finish; // End simulation after some time
  end

endmodule



