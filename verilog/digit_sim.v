module digit_sim (
    
);  reg clk=0;
    wire [7:0]  segs; 

    always #10 clk=~clk;
    
    digit d(clk,segs);
    display
endmodule