#include <bits/stdc++.h>
using namespace std;

// 二维dp
int main() {
    int n, v;
    cin >> n >> v;

    std::vector<int> weight(n, 0), value(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<vector<int>> dp(n, vector<int>(v + 1, 0));

    for (int i = weight[0]; i < v + 1; i++) {
        dp[0][i] = dp[0][i - weight[0]] + value[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < v + 1; j++) {
            if (j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n - 1][v] << endl;
    return 0;
}

// 一维dp
int main() {
    int n, v;
    cin >> n >> v;

    std::vector<int> weight(n, 0), value(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<int> dp(v + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v + 1; j++) {
            if (j >= weight[i])
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[v] << endl;
    return 0;
}