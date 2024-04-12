module mux2x1_sim (
    
);
    reg a=0;
    reg b=1;
    reg s=0;
    wire c;
    mux2x1 u(.a(a),.b(b),.s(s),.c(c));

    initial begin
        #200 s=1;
    end


endmodule