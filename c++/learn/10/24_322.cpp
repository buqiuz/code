#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<uint64_t> dp(amount + 1, INT32_MAX);

        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j < amount + 1; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == INT32_MAX ? -1 : dp[amount];
    }
};