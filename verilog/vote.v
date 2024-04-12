module VoteCounter (
  input wire [10:0] votes,  // 输入端口，11个人的投票，1表示赞成，0表示反对
  output reg decision     // 输出端口，1表示表决通过，0表示表决未通过
);

reg [7:0] count; // 内部寄存器，用于计数赞成票数

always @(votes) begin
  // 使用for循环计算赞成票数
  count = 0;
  for (integer i = 0; i < 11; i = i + 1) begin
    if (votes[i] == 1) begin
      count = count + 1;
    end
  end

  // 如果赞成票数超过6，则表决通过
  if (count >= 6) begin
    decision = 1;
  end
  else begin
    decision = 0;
  end
end


endmodule
