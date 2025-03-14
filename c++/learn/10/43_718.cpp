#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int ret = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                ret = max(ret, dp[i + 1][j + 1]);
            }
        }
        return ret;
    }
};
// 优化
class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        vector<int> dp(nums2.size() + 1, 0);
        int ret = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j])
                    dp[j + 1] = dp[j] + 1;
                else
                    dp[j + 1] = 0;
                ret = max(ret, dp[j + 1]);
            }
        }
        return ret;
    }
};