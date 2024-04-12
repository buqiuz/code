module hexseg5_1sim (
    
);
    reg [3:0] hex=4'h0;

    wire  [6:0] segs;
    hexseg5_1 h(hex, segs);
    initial begin
        
        for (integer i=0;i<16;i=i+1) begin
            #50;
            hex=hex+1;
        end

    end
endmodule
