#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> dp(3, 0);
        dp[0] = -prices[0]; // 第一天买入股票
        dp[1] = 0;          // 第一天不可能卖出
        dp[2] = 0;          // 第一天不可能进入冷冻期

        for (int i = 1; i < prices.size(); i++) {
            int prev_dp0 = dp[0]; // 记录前一天的 dp[0]
            int prev_dp1 = dp[1]; // 记录前一天的 dp[1]
            int prev_dp2 = dp[2]; // 记录前一天的 dp[2]

            dp[0] = max(dp[0], dp[2] - prices[i]); // 只能从冷冻期转移到持有股票状态
            dp[1] = dp[0] + prices[i];             // 只能从持有股票状态卖出
            dp[2] = max(dp[2], prev_dp1);          // 只能从卖出状态进入冷冻期
        }
        return max(dp[1], dp[2]); // 返回不持有股票的最大利润
    }
};