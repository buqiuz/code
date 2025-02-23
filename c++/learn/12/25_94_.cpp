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

    vector<int> minDist(n + 1, INT32_MAX);
    vector<bool> isInQueue(n + 1, false);
    queue<int> que;

    minDist[1] = 0;
    isInQueue[1] = true;
    que.push(1);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        isInQueue[cur] = false;
        for (auto [v, w] : adj[cur]) {
            if (minDist[v] > minDist[cur] + w) {
                minDist[v] = minDist[cur] + w;
                if (!isInQueue[v])
                    que.push(v);
            }
        }
    }

    if (minDist[n] == INT32_MAX)
        cout << "unconnected" << endl;
    else
        cout << minDist[n];

    return 0;
}