module decode38 (
    input wire [2:0]    a,
    input wire [2:0]    b,
    output wire [7:0]   c
);

    assign c=(a==3'b100)?(8'b11111111-(8'b00000001<<b)):(8'b11111111);
    
endmodule
