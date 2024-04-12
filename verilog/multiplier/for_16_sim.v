module multiplier_16_sim(

    );
    reg [15:0] a=16'b0000_1000_1000_1000;
    reg [15:0] b=16'b1000_0001_1000_0010;
    wire [31:0] c;
    multiplier_16 m(a,b,c);
    initial begin
        #20 begin a=10;b=30; end 
    end
endmodule