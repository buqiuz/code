#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(n + 1, INT32_MAX);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        // 开始松弛
        bool updated = false;
        for (int u = 1; u <= n; u++) {
            for (auto [v, w] : adj[u]) {
                if (dist[u] != INT32_MAX && dist[u] + w < dist[v]) {
                    updated = true;
                    dist[v] = dist[u] + w;
                }
            }
        }
        // 如果没有更新，提前退出
        if (!updated) {
            break;
        }
    }
    // 检测负环
    for (int i = 1; i <= n; i++) {
        for (auto [v, w] : adj[i]) {
            if (dist[i] != INT32_MAX && dist[i] + w < dist[v]) {
                cout << "circle" << endl;
                return 0;
            }
        }
    }

    if (dist[n] == INT32_MAX)
        cout << "unconnected" << endl;
    else
        cout << dist[n];

    return 0;
}