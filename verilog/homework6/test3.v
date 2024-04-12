module test3(
    input wire clk,
    input wire rst_n,
    input wire in,
    output wire test
    );
    reg test_r;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            test_r <= 1'b0; // 异步复位时赋值0
        end
        else begin
            if(in)
                test_r <= in;
        end
    end
    assign test=test_r;

endmodule
