module multiplier_16 (
    input [15:0] a,
    input [15:0] b,
    output  [31:0] out
);
        reg [31:0] c;
        always@(*) begin
            c = 0;
            for ( integer i = 0; i < 16; i=i+1) begin
                if(b[i]) begin
                c = c + ( a << i);
                end
            end
        end
        assign out =c;

endmodule
