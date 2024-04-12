module ClockSimulation;

reg clk;
wire [3:0] sec1, sec0, min1, min0, hour1, hour0;

// Instantiate the HexadecimalClock module
HexadecimalClock Clock1 (
    .clk(clk),
    .sec1(sec1),
    .sec0(sec0),
    .min1(min1),
    .min0(min0),
    .hour1(hour1),
    .hour0(hour0)
);

// Clock generation (50 MHz)
always 
    #5 clk = ~clk;


initial begin
    clk = 0;
    // Simulate for 10 seconds
    #100000000;

    // Display time
    $display("Time: %d%d:%d%d:%d%d", hour1, hour0, min1, min0, sec1, sec0);
    
    // Finish simulation
    $finish;
end

endmodule
