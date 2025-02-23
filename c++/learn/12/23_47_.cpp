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
    vector<bool> visited(n + 1, false);
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    pq.push({1, 0});
    dist[1] = 0;
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        visited[cur.first] = true;

        for (auto [v, w] : adj[cur.first]) {
            if (!visited[v] && dist[v] > dist[cur.first] + w) {
                dist[v] = dist[cur.first] + w;
                pq.push({v, dist[v]});
            }
        }
    }

    cout << (dist[n] == INT32_MAX ? -1 : dist[n]);

    return 0;
}