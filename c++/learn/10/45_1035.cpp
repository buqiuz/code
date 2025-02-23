#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int ret = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                ret = max(ret, dp[i + 1][j + 1]);
            }
        }
        return ret;
    }
};

class Solution {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        vector<int> dp(nums2.size() + 1, 0);
        int ret = 0;
        int prev = 0, temp = 0;
        for (int i = 0; i < nums1.size(); i++) {
            prev = 0;   //每次循环开始时，prev都是0
            for (int j = 0; j < nums2.size(); j++) {
                temp = dp[j + 1];  //先保存，再更新，下一次循环用
                if (nums1[i] == nums2[j])
                    dp[j + 1] = prev + 1;
                else
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                ret = max(ret, dp[j + 1]);
                prev = temp;
            }
        }
        return ret;
    }
};