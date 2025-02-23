#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        // vector<int> dp(word2.size() + 1);
        int dp[word2.size() + 1];
        for (int j = 0; j <= word2.size(); j++)
            dp[j] = j;

        int temp = 0;
        int prev = 0;
        for (int i = 1; i <= word1.size(); i++) {
            prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= word2.size(); j++) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = prev;
                else
                    dp[j] = min(dp[j], dp[j - 1]) + 1;
                prev = temp;
            }
        }
        return dp[word2.size()];
    }
};