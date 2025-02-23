#include <bits/stdc++.h>
using namespace std;

class Solution {
    int get_rob(vector<int> &nums, int start, int end) {
        if ((end - start) == 1)
            return max(nums[start], nums[end]);
        vector<int> dp(end + 1, 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }

public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        if (size == 1)
            return nums[0];
        if (size == 2)
            return max(nums[0], nums[1]);

        int ret1 = get_rob(nums, 0, size - 2);
        int ret2 = get_rob(nums, 1, size - 1);
        return max(ret1, ret2);
    }
};