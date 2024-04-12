module hexseg5_1(
    input [3:0]hex,
    
    output wire [6:0] segs  //必须用wire类型  为啥呢？
    
    );
    reg a=1 ;
    wire b;
    hexseg_0 h(hex,a,b,segs);
    
    
endmodule
