module decode416_sim(

    );
    reg [3:0] a=4'b1001;
    wire [15:0] c;
    decode416 d(a,c);
    initial begin
        #100
        a=4'b1010;
        #100
        a=4'b1011;
    end
    
endmodule