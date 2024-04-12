module mux4x1_sim (
    
);
    reg a=0,b=1,c=1,d=0,s0=0,s1=0;
    wire y;
    mux4x1 u(a,b,c,d,s0,s1,y);
    initial begin
        #200 s1=1;
        #200 begin
            s0=1;s1=0;

        end
        #200 s1=1;
    end
endmodule