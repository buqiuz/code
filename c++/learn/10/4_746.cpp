#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int size = cost.size();
        vector<int> dp(size + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i < size + 1; i++) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[size];
    }
};