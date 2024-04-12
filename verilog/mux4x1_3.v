module mux4x1_3 (
    input [2:0] a,
    input [2:0] b,
    input [2:0] c,
    input [2:0] d,
    input [1:0] s,
    output reg [2:0] y

);
    always @(*) begin
        case (s)

            2'b00:  y=a;
            2'b01:  y=b;
            2'b10:  y=c;
            2'b11:  y=d;

            default: y=3'b000;
        endcase
    end
    
endmodule