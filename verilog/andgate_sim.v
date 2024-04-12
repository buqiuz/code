module andgate_sim (
    
);
    reg [31:0]  a=32'h00000000;
    reg [31:0]  b=32'h00000000;
    wire [31:0] c;
    andgate #(32) u(a,b,c);
    
    initial begin
        #100 a=32'hffffffff;
        #100 a=32'hf0000000;b=32'hffffffff;
        #100 a=32'hffffffff;
    end

    
endmodule