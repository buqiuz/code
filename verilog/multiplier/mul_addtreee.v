module mul_addtree(
            clk     ,
            rst_n   ,
            vld_in  ,
            x       ,
            y       ,
            p       ,
            vld_out      
);

input      clk                      ;
input      rst_n                    ;
input      vld_in                   ;
input      x                        ;
input      y                        ;
output     p                        ; 
output     vld_out                  ; 

wire [3:0] x                        ;
wire [3:0] y                        ;
reg  [7:0] p                        ;
wire       vld_in                   ;
reg        vld_out                  ;
reg        vld_in_ff0               ;

wire [7:0] a0                       ;
wire [7:0] b0                       ;
wire [7:0] a1                       ;
wire [7:0] b1                       ;

reg  [7:0] tmp0                     ;
reg  [7:0] tmp1                     ;

assign a0 = x[0]?{4'b0,y}: 0        ;
assign b0 = x[1]?{3'b0,y,1'b0}: 0   ;

assign a1 = x[2]?{2'b0,y,2'b0} : 0  ;
assign b1 = x[3]?{1'b0,y,3'b0} : 0  ;




always  @(posedge clk or negedge rst_n)begin
    if(rst_n==1'b0)begin
        tmp0 <= 0;
    end
    else if(vld_in) begin
        tmp0 <= a0 + b0 ;
    end
end

always  @(posedge clk or negedge rst_n)begin
    if(rst_n==1'b0)begin
        tmp1 <= 0;
    end
    else if(vld_in) begin
        tmp1 <= a1 + b1;
    end
end

always  @(posedge clk or negedge rst_n)begin
    if(rst_n==1'b0)begin
        p <= 0;
    end
    else if(vld_in_ff0) begin
        p <= {2'b0,tmp0} + tmp1;
    end
end



always  @(posedge clk or negedge rst_n)begin
    if(rst_n==1'b0)begin
        vld_out    <= 0;
        vld_in_ff0<=0;
    end
    else  begin
        vld_in_ff0  <= vld_in;
        vld_out  <= vld_in_ff0;
    end
end

endmodule


