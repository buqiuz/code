module add32_4_test( );
    reg [31:0] a;
    reg [31:0] b;
    reg clk;
    reg rst;
    reg cin;
    reg stop;
    wire cout;
    wire [31:0] sum;
    
    
    initial begin
        clk = 1;
        rst = 0;
        stop = 0;
        a = 32'h0000_0000;b=32'h0000_0000;cin=1'b0;
        @(posedge clk) 
        
                       a = 32'h0000_0000;b=32'h0000_0000;cin=1'b0;
        @(posedge clk) a = 32'h0000_0000;b=32'h0000_0000;cin=1'b0;
        @(posedge clk) a = 32'h0000_0001;b=32'h0000_0001;cin=1'b0;
        @(posedge clk) a = 32'h0000_0010;b=32'h0000_0001;cin=1'b0;
        @(posedge clk) a = 32'h0000_1000;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) a = 32'h0000_0100;b=32'h0000_0001;cin=1'b0;
        @(posedge clk) a = 32'h0010_0000;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) a = 32'h0010_0000;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) stop=1;a = 32'h0100_0000;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) a = 32'h1000_0001;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) stop=0;a = 32'h1000_1111;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) a = 32'h1000_0001;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) a = 32'h1000_0001;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) a = 32'h1000_0001;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) rst=1;a = 32'h1000_0001;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) a = 32'h1000_1011;b=32'h0100_0001;cin=1'b1;
        @(posedge clk) a = 32'h1010_1011;b=32'h0000_0001;cin=1'b1;
        @(posedge clk) a = 32'h1000_0111;b=32'h0000_0001;cin=1'b1;
        repeat(10) @(posedge clk);
        $finish;       
    end
    
    always #5  clk = ~clk;

    add32_4 a(a,b,rst,clk,stop,cin,cout,sum);

endmodule
