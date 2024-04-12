module SequenceComparatorFSM (
  input wire clk,            // 时钟输入
  input wire reset,          // 复位输入
  input wire w1,             // 输入位 w1
  input wire w2,             // 输入位 w2
  output reg z               // 输出位 z
);

  // 定义状态
parameter 
    S0=0,    // 空闲状态
    S1=1,  // 等待第1个相等输入
    S2=2,  // 等待第2个相等输入
    S3=3,  // 等待第3个相等输入
    S4=4;   // 输出状态
 
  reg [1:0] current_state, next_state;  // 当前状态和下一个状态
  reg [3:0] count;                      // 计数器，用于计算连续时钟周期数

  // 状态转移逻辑
  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      current_state <= S0;  // 复位时将状态机置为初始状态
      count <= 4'b0;            // 复位时将计数器清零
    end else begin
      current_state <= next_state;  // 更新状态
    end
  end

  // 状态机逻辑
  always_ff @(posedge clk) begin
    case (current_state)
      S0:
        if (w1 == w2) begin
          next_state = S1;
        end else begin
          next_state = S0;
        end
      S1:
        if (w1 == w2) begin
          next_state = S2;
        end else begin
          next_state = S0;
        end
      S2:
        if (w1 == w2) begin
          next_state = S3;
        end else begin
          next_state = S0;
        end
      S3:
        if (w1 == w2) begin
          next_state = S4;
        end else begin
          next_state = S0;
        end
      S4:
        next_state = S0;  // 输出状态后返回到空闲状态
    endcase
  end

  // 计数器逻辑
  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      count <= 4'b0;  // 复位时将计数器清零
    end else begin
      if (current_state == S4) begin
        count <= 4'b0;  // 在输出状态时计数器清零
      end else begin
        count <= count + 1;  // 在其他状态时增加计数器
      end
    end
  end

  // 输出逻辑
  always_comb begin
    z = (count == 4'b3) ? 1'b1 : 1'b0;  // 如果连续4个周期，设置输出为1，否则为0
  end

endmodule
