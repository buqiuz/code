module moduleName (
    
);
    wire clk;
    reg [2:0]a,b,c,d;
    reg[6:0]segs0,segs1,segs2,segs3;
    hexseg5_3 hh(clk,a,b,c,d,segs0,segs1,segs2,segs3);
    initial begin
        #100 begin
            a=3'b000;
            b=3'b001;
            c=3'b010;
            d=3'b100;
        end
        #100 begin
            a=3'b111;
            b=3'b110;
            c=3'b100;
            d=3'b000; 
        end   
    end
endmodule