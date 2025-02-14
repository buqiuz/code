#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<uint64_t> dp(target + 1, 0);
        dp[0] = 1;

        // for(int i=0;i<nums.size();i++){             //组合问题，外层循环是物品，内层循环是背包
        //     for(int j=nums[i];j<target+1;j++){
        //         dp[j]+=dp[j-nums[i]];
        //     }
        // }
        for (int j = 0; j < target + 1; j++) {         //排序问题，外层循环是背包，内层循环是物品
            for (int i = 0; i < nums.size(); i++) {
                if (j >= nums[i])
                    dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};