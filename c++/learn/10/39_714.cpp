#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        vector<int> dp(2, 0);
        dp[0] = -prices[0];
        dp[1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[0] = max(dp[0], dp[1] - prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i] - fee);
        }
        return dp[1];
    }
};