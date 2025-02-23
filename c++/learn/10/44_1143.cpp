#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        int ret = 0;
        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                if (text1[i] == text2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                ret = max(ret, dp[i + 1][j + 1]);
            }
        }
        return ret;
    }
};

//优化
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text2.size() + 1, 0); // 只用一维数组
        int prev = 0, temp = 0;              // prev 代表 dp[i-1][j-1]

        for (int i = 0; i < text1.size(); i++) {
            prev = 0; // 代表左上角的 dp[i-1][j-1]
            for (int j = 0; j < text2.size(); j++) {
                temp = dp[j + 1]; // 先保存 dp[j+1]（相当于 dp[i-1][j]）
                if (text1[i] == text2[j])
                    dp[j + 1] = prev + 1; // dp[i][j] = dp[i-1][j-1] + 1
                else
                    dp[j + 1] = max(dp[j + 1], dp[j]); // max(dp[i-1][j], dp[i][j-1])
                prev = temp;                           // 更新 prev，作为下一轮的 dp[i-1][j-1]
            }
        }
        return dp[text2.size()];
    }
};
