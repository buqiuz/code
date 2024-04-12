module hexseg_sim (
    
);
    reg [3:0] hex=4'h0;
    reg  en=1;
    wire  an;
    wire  [6:0] segs;
    hexseg h(hex,en,an,segs);
    initial begin
        
        for (integer i=0;i<16;i=i+1) begin
            #50
            hex=hex+1;
        end

    end
endmodule