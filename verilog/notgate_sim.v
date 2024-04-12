module notgate_sim (
    
);
    reg[31:0] a=32'h00000000;
    wire [31:0]b;
    notgate #(32) u(a,b);
    initial begin
        #100 a=32'hffffffff;
        #100 a=32'hfff00000;
    end
endmodule