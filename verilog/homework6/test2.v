module test2(
    input wire clk,
    input wire rst_n,
    input wire in,
    output reg test_r
    );
    always @(negedge clk) begin
    if(!rst_n) begin
        test_r <= 1;
        end
        else begin
        test_r <= in;
    end
end

endmodule
