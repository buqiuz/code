#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                if (s[i] == t[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = dp[i + 1][j];
            }
        }
        if (dp[s.size()][t.size()] == s.size())
            return true;
        return false;
    }
};