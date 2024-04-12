module hexseg5_2_sim (
    
);
    reg a=3'b000,b=3'b001,c=3'b010,d=3'b100,s=2'b00;
    wire [6:0]  segs;
    hexseg5_2 h(a,b,c,d,s,segs);
    initial begin
        #100
        s=2'b01;
        #100
        s=2'b10;
        #100
        s=2'b11;
    end
endmodule