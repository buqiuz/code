#include <bits/stdc++.h>
using namespace std;

// 回溯，会超时，并且可以用vector代替unordered_map
class Solution {
private:
    int ret = 0;
    void backTrack(unordered_map<int, pair<int, int>> &mp, int count_0, int count_1, int startIndex, int m, int n,
                   int selectedCount) {
        // 更新结果：使用实际选中的字符串数量
        ret = max(ret, selectedCount);

        // 遍历所有可能的选择
        for (int i = startIndex; i < mp.size(); i++) {
            // 剪枝：计算选择当前元素后的0和1的个数
            int new_count_0 = count_0 + mp[i].first;
            int new_count_1 = count_1 + mp[i].second;

            // 如果超出限制，跳过
            if (new_count_0 > m || new_count_1 > n) {
                continue;
            }

            // 递归：注意传入 selectedCount + 1
            backTrack(mp, new_count_0, new_count_1, i + 1, m, n, selectedCount + 1);
        }
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < strs.size(); i++) {
            for (auto x : strs[i]) {
                if (x == '0')
                    mp[i].first++;
                else
                    mp[i].second++;
            }
        }
        backTrack(mp, 0, 0, 0, m, n, 0); // 最后一个参数是选中计数
        return ret;
    }
};

// 动态规划 dp[i][j]表示有i个0和j个1时能组成的最多字符串的个数
class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto &x : strs) {
            int count_0 = count(x.begin(), x.end(), '0');
            int count_1 = x.size() - count_0;
            for (int i = m; i >= count_0; i--) {
                for (int j = n; j >= count_1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - count_0][j - count_1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};