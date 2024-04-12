module digit_hdl_sim(

    );
    reg clk=0;
    reg rstn=0;
    wire [7:0] seg;
    wire [3:0] sel;
    wire [3:0] hours1;
    wire [2:0] hours2;
    digital_hdl_new d (clk,
    hours1,
    hours2,
    rstn,
    seg,
    sel);
    
    always
        #5 clk=~clk;
        
        initial begin
         #500 rstn =1;
        end
endmodule
