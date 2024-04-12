module multiplier_16 (
a,b,outcome
);
parameter size =16 ;
output [2*size:1] outcome;
input [size:1] a,b;
reg [2*size:1]outcome;
integer i;
    always @(a or b) begin
        outcome=0;
        for (i =1 ;i<=size ;i=i+1 ) begin
            if(b[i]) outcome=outcome+(a<<(i-1));
        end
    end

endmodule