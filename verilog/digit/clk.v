module ClockDivider (
    input wire clk_input,      // 输入时钟为100 MHz
    output reg sec_clk,       // 秒级时钟
    output reg ms_4_clk       // 4 ms时钟
);

reg [31:0] count_sec; // 秒级时钟计数器
reg [31:0] count_4ms; // 4 ms时钟计数器

parameter CLK_DIVIDE_SEC = 100000000; // 分频100 MHz以获得1 Hz秒级时钟
parameter CLK_DIVIDE_4MS = 250000;    // 分频100 MHz以获得4 ms时钟

always @(posedge clk_input) begin
    if (count_sec == CLK_DIVIDE_SEC - 1) begin
        sec_clk <= ~sec_clk; // 切换秒级时钟边沿
        count_sec <= 0;
    end else begin
        count_sec <= count_sec + 1'b1;
    end

    if (count_4ms == CLK_DIVIDE_4MS - 1) begin
        ms_4_clk <= ~ms_4_clk; // 切换4 ms时钟边沿
        count_4ms <= 0;
    end else begin
        count_4ms <= count_4ms + 1'b1;
    end
end

endmodule
