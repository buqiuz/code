#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int m = stones.size();
        int n = total / 2;

        vector<int> dp(n + 1, 0);

        for (int i = 0; i < stones.size(); i++) {
            for (int j = n; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return total - 2 * dp[n];
    }
};