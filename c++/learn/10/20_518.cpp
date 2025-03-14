#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 0; j < amount + 1; j++) {
                if (j >= coins[i])
                    dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};