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

    int src, dst, k;
    cin >> src >> dst >> k;

    vector<int> dist(n + 1, INT32_MAX);
    vector<int> dist_copy(n + 1);
    dist[src] = 0;
    for (int i = 0; i <= k; i++) {
        dist_copy = dist;
        for (int u = 1; u <= n; u++) {
            for (auto [v, w] : adj[u]) {
                // 如果不用dist_copy，会导致dist[v]在更新的时候，dist[u] 已经被更新了，导致dist[v]的值不正确,变成了滚动数组
                if (dist_copy[u] != INT32_MAX && dist[v] > dist_copy[u] + w)
                    dist[v] = dist_copy[u] + w;
            }
        }
    }

    if (dist[dst] == INT32_MAX)
        cout << "unreachable" << endl;
    else
        cout << dist[dst] << endl;

    return 0;
}