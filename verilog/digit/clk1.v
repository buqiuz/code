module ClockGenerator (
    input wire clk_input,      // 输入时钟为100 MHz
    output wire sec_clk,       // 秒级时钟
    output wire ms_1_clk       // 1 ms时钟
);

reg [27:0] count_sec=0;  
reg [19:0] count_ms_1=0; 
reg sec_clk0=0;
reg ms_1_clk0=0;

always @(posedge clk_input) begin
    if (count_sec == 50000000-1) 
        begin
            sec_clk0 <= ~sec_clk0; 
            count_sec <= 0;
        end
    else
        count_sec <= count_sec + 1'b1;

    if (count_ms_1 == 50000-1) 
        begin
            ms_1_clk0 <= ~ms_1_clk0; 
            count_ms_1 <= 0;
        end
    else
        count_ms_1 <= count_ms_1 + 1'b1;
end

assign ms_1_clk=ms_1_clk0;
assign  sec_clk= sec_clk0;

endmodule