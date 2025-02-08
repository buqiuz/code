#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // 含义
        vector<int> dp(n + 1, 0);

        // 初始化
        dp[0] = 1;

        // 遍历方向
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < i; j++) {
                // 递推公式
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};