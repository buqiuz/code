module hexseg5_2(
    input [2:0] a,
    input [2:0] b,
    input [2:0] c,
    input [2:0] d,
    input [1:0] s,
    output [6:0] segs
    );
    reg w=1;
    wire b;
    wire [2:0] hex;
    mux4x1_3_0 m(a,b,c,d,s,hex);
    hexseg_0 h(hex,w,b,segs);
    
endmodule