#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0)
            return false;

        int m = nums.size();
        int n = total / 2;

        vector<int> dp(n + 1, 0);

        for (int i = 1; i < m; i++) {
            for (int j = n; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return dp[n] == n;
    }
};