module hexseg (
    input [3:0] hex,
    input en,
    output an,
    output reg [6:0] segs   
);
    assign an=en+1;
        always @(*) begin
            case (hex)
                4'h0: segs=7'b000_0001;
                4'h1: segs=7'b100_1111;
                4'h2: segs=7'b001_0010;
                4'h3: segs=7'b000_0110;
                4'h4: segs=7'b100_1100;
                4'h5: segs=7'b010_0100;
                4'h6: segs=7'b010_0000;
                4'h7: segs=7'b000_1111;
                4'h8: segs=7'b000_0000;
                4'h9: segs=7'b000_1100;
                4'ha: segs=7'b000_1000;
                4'hb: segs=7'b110_0000;
                4'hc: segs=7'b111_0010;
                4'hd: segs=7'b100_0010;
                4'he: segs=7'b011_0000;
                4'hf: segs=7'b011_1000;

                default: 
                    segs=7'b111_1111;
            endcase
        end
    
endmodule