module HexadecimalClock_new (
    input wire clk,         // 输入时钟
    input wire rstn,       // 复位信号
    output wire [3:0] sec1, // 六十进制秒的第一个四位
    output wire [3:0] sec0, // 六十进制秒的第二个四位
    output wire [3:0] min1, // 六十进制分钟的第一个四位
    output wire [3:0] min0, // 六十进制分钟的第二个四位
    output wire [3:0] hour1, // 六十进制小时的第一个四位
    output wire [3:0] hour0  // 六十进制小时的第二个四位
);

reg [3:0] sec1_reg = 4'b0; // 初始化秒的第一个四位为0
reg [3:0] sec0_reg = 4'b0; // 初始化秒的第二个四位为0
reg [3:0] min1_reg = 4'b0; // 初始化分钟的第一个四位为0
reg [3:0] min0_reg = 4'b0; // 初始化分钟的第二个四位为0
reg [3:0] hour1_reg = 4'b0; // 初始化小时的第一个四位为0
reg [3:0] hour0_reg = 4'b0; // 初始化小时的第二个四位为0

always @(posedge clk or negedge rstn) begin
    if (!rstn) begin
        sec1_reg <= 4'b0;
        sec0_reg <= 4'b0;
        min1_reg <= 4'b0;
        min0_reg <= 4'b0;
        hour1_reg <= 4'b0;
        hour0_reg <= 4'b0;
    end else begin
        // 同样的逻辑如之前的代码，用于递增时间
        if (sec1_reg == 5 && sec0_reg == 9) begin
            sec1_reg <= 4'b0;
            sec0_reg <= 4'b0;
            if (min1_reg == 5 && min0_reg == 9) begin
                min1_reg <= 4'b0;
                min0_reg <= 4'b0;
                if (hour1_reg == 2 && hour0_reg == 3) begin
                    hour1_reg <= 4'b0;
                    hour0_reg <= 4'b0;
                end else begin
                    hour0_reg <= hour0_reg + 1;
                    if (hour0_reg == 9) begin
                        hour0_reg <= 4'b0;
                        hour1_reg <= hour1_reg + 1;
                    end
                end
            end else begin
                min0_reg <= min0_reg + 1;
                if (min0_reg == 9) begin
                    min0_reg <= 4'b0;
                    min1_reg <= min1_reg + 1;
                end
            end
        end else begin
            sec0_reg <= sec0_reg + 1;
            if (sec0_reg == 9) begin
                sec0_reg <= 4'b0;
                sec1_reg <= sec1_reg + 1;
            end
        end
    end
end

assign sec1 = sec1_reg;
assign sec0 = sec0_reg;
assign min1 = min1_reg;
assign min0 = min0_reg;
assign hour1 = hour1_reg;
assign hour0 = hour0_reg;

endmodule

