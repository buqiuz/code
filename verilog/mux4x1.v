module mux4x1verilog(
input a,
input b,
input c,
input d,
input s0,
input s1,
output y
    );
    wire y1,y2;
    mux2x1_0 m0(a,b,s0,y1);
    mux2x1_0 m1(c,d,s0,y2);
    mux2x1_0 m2(y1,y2,s1,y);
endmodule