#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) {
                ret += diff;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> dp(2, 0);
        dp[0] = -prices[0];
        dp[1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[0] = max(dp[0], dp[1] - prices[i]); // 第i天买入
            dp[1] = dp[0] + prices[i];             // 第i天卖出
        }
        return dp[1];
    }
};