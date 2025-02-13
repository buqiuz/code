#include <bits/stdc++.h>
using namespace std;

// 初版
class Solution {
private:
    int count = 0;
    void backTrack(vector<int> &nums, int &target, int index, int sum) {
        if (index == nums.size() && sum == target) {
            count++;
            return;
        }
        if (index == nums.size())
            return;

        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                sum -= nums[index];
                backTrack(nums, target, index + 1, sum);
                sum += nums[index];
            } else {
                sum += nums[index];
                backTrack(nums, target, index + 1, sum);
                sum -= nums[index];
            }
        }
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        backTrack(nums, target, 0, 0);
        return count;
    }
};

// 简化版  二叉树
class Solution {
private:
    int count = 0;
    void backTrack(vector<int> &nums, int &target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target)
                count++;
            return;
        }

        backTrack(nums, target, index + 1, sum - nums[index]);
        backTrack(nums, target, index + 1, sum + nums[index]);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        backTrack(nums, target, 0, 0);
        return count;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if ((total + target) % 2 == 1)
            return 0;
        if (abs(target) > total)
            return 0;

        int m = nums.size();
        int n = (total + target) / 2;
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        if (nums[0] <= n)
            dp[nums[0]] = 1;

        if (nums[0] == 0)
            dp[0] *= 2;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = n; j >= nums[i]; j--) {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }

        return dp[n];
    }
};

// 精简版
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if ((total + target) % 2 == 1)
            return 0;
        if (abs(target) > total)
            return 0;

        int m = nums.size();
        int n = (total + target) / 2;
        vector<int> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = n; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[n];
    }
};
