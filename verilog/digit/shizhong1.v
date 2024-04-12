module digital(
  input clk_1khz,
  input rstn,
  input [3:0] sec0,
  input [3:0] sec1,
  input [3:0] min0,
  input [3:0] min1,
  input [3:0] hour0,
  input [3:0] hour1,
  output reg[7:0] seg,
  output reg[3:0] sel,
  output reg[3:0] hours1,
  output reg[2:0] hours2
);


reg [3:0] tub;
reg [2:0] state;

always @(posedge clk_1khz or negedge rstn) begin
    if (!rstn) begin
        tub <= 0;
        state <= 0;
        sel <= 0;
        hours1 <= 0;
        hours2 <= 0;
    end else begin
        case (state)
            0: begin
                hours1 <= hour0;
                sel <= 4'b1111;
                state <= 1;
            end
            1: begin
                hours2 <= hour1;
                sel <= 4'b1111;
                state <= 2;
            end
            2: begin
                tub <= min1;
                sel <= 4'b0111;
                state <= 3;
            end
            3: begin
                tub <= min0;
                sel <= 4'b1011;
                state <= 4;
            end
            4: begin
                tub <= sec1;
                sel <= 4'b1101;
                state <= 5;
            end
            5: begin
                tub <= sec0;
                sel <= 4'b1110;
                state <= 0;
            end
            default: state <= 0;
        endcase
    end
end

always @(*) begin
    if (!rstn) begin
        seg <= 8'b1100_0000;
    end else begin
        case (tub)
            0: seg <= 8'b1100_0000;
            1: seg <= 8'b1111_1001;
            2: seg <= 8'b1010_0100;
            3: seg <= 8'b1011_0000;
            4: seg <= 8'b1001_1001;
            5: seg <= 8'b1001_0010;
            6: seg <= 8'b1000_0010;
            7: seg <= 8'b1111_1000;
            8: seg <= 8'b1000_0000;
            9: seg <= 8'b1001_0000;
            default: seg <= 8'b1100_0000;
        endcase
    end
end

endmodule


