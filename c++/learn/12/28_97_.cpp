#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT32_MAX));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = w;
        dp[v][u] = w;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] != INT32_MAX && dp[k][j] != INT32_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (dp[u][v] == INT32_MAX ? -1 : dp[u][v]) << endl;
    }
    return 0;
}