module VoteCounterTest;

  reg [10:0] test_votes; // 输入端口，11个人的投票
  wire test_decision;   // 输出端口，表决结果
  integer i;

  // 实例化投票表决器模块
  VoteCounter vote_counter (
    .votes(test_votes),
    .decision(test_decision)
  );

  initial begin
    // 仿真测试不同的投票情况 
    test_votes = 0;
    
    // 循环测试不同投票情况
    for (i = 0; i <= 2048; i = i + 1) begin
      test_votes = i;
      #0.46; 
    end
    $finish;
  end

endmodule