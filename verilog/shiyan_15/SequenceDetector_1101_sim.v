module SequenceDetector_1101_sim;
    reg clk;
    reg reset;
    wire check;
    reg in;
    
    //时钟设计
    initial
        begin
            clk = 1'b0;
        end
     always begin
        #10; clk = ~clk;
     end
     //reset信号
     initial begin
        reset = 1'b0;
        #5;
        reset = 1'b1;
        #10;
        reset <= 1'b0;
     end
     //in信号
     initial begin
        in = 1'b0;
        #20;
        in = 1'b1;
        #40;
        in = 1'b0;
        #20;
        in = 1'b1;
        #40;
        in = 1'b0;
        #20;
        in = 1'b1;
        
     end
     
     SequenceDetector_1101 u1(
        .clk(clk),
        .in(in),
        .rst_n(reset),
        .out(check)
     );
endmodule
