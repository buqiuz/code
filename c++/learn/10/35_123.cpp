#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> dp(4, 0);
        dp[0] = -prices[0];
        dp[1] = 0;
        dp[2] = -prices[0];
        dp[3] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[0] = max(dp[0], -prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]); // 第i天第一次卖出，只能卖出一次，所以取最大值
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[3] = max(dp[3], dp[2] + prices[i]); // 第i天第二次卖出，只能卖出一次，所以取最大值
        }
        return dp[3];
    }
};