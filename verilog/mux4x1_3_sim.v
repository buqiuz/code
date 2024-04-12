module mux4x1_3_sim (
    
);
    reg a=3'b000,b=3'b001,c=3'b010,d=3'b100,s=2'b00,y;//有错误
    
    mux4x1_3 u(a,b,c,d,s,y);
    initial begin
        #200 s=2'b01;
        #200 s=2'b10;
        #200 s=2'b11;

    end
endmodule