#include <bits/stdc++.h>
using namespace std;

// 贪心
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int low = INT32_MAX;
        int ret = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);
            ret = max(ret, prices[i] - low);
        }
        return ret;
    }
};

// 动态规划
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> dp(2, 0);

        dp[0] = -prices[0];
        dp[1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[0] = max(dp[0], -prices[i]);        // 买入   
            dp[1] = max(dp[1], prices[i] + dp[0]); // 卖出   只能卖出一次，所以取最大值
        }
        return dp[1];
    }
};