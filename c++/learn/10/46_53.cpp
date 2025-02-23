#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(1, 0);
        int ret = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            dp[0] = max(dp[0] + nums[i], nums[i]);
            ret = max(dp[0], ret);
        }
        return ret;
    }
};
