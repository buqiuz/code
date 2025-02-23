#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT32_MAX));
    for (int i = 0; i < m; i++) {
        int l, r, val;
        cin >> l >> r >> val;
        grid[l][r] = val;
    }

    vector<int> minDist(n + 1, INT32_MAX);
    vector<bool> visited(n + 1, false);

    minDist[1] = 0;
    for (int i = 1; i <= n; i++) {
        int cur = 1;
        int curMIn = INT32_MAX;
        // 找距离源点最短的节点
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && minDist[j] < curMIn) {
                cur = j;
                curMIn = minDist[j];
            }
        }

        // 加入节点
        visited[cur] = true;

        // 更新距离
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && grid[cur][j] != INT32_MAX && grid[cur][j] + minDist[cur] < minDist[j])
                minDist[j] = grid[cur][j] + minDist[cur];
        }
    }

    cout << (minDist[n] == INT32_MAX ? -1 : minDist[n]);

    return 0;
}