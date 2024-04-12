module decode38_sim (
    
);
    reg [2:0]   a=3'b100    ,b=3'b000;
    wire [7:0]   c;
    decode38 d(a,b,c);
    initial begin
        #50;
        for(integer i=0;i<8;i=i+1)begin
            b=b+1;
            #10;
        end
        a=3'b111;
        for (integer i =0 ;i<8  ;i=i+1 ) begin
            a=a+1;
            for (integer j=0 ;j<8 ;j=j+1 ) begin
                #10;
                b=b+1;
                
            end
        end

    end


endmodule