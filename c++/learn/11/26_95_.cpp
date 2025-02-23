// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<pair<int, int>>> adj(n + 1);
//     for (int i = 0; i < m; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//     }

//     vector<int> minDist(n + 1, INT32_MAX);

//     minDist[1] = 0;
//     int last = 0;
//     for (int i = 0; i < n; i++) {
//         for (int u = 1; u <= n; u++) {
//             for (auto [v, w] : adj[u]) {
//                 if (minDist[u] != INT32_MAX && minDist[v] > minDist[u] + w)
//                     minDist[v] = minDist[u] + w;
//             }
//         }
//         if (i == n - 2)
//             last = minDist[n];
//     }

//     if (last != minDist[n])
//         cout << "circle" << endl;
//     else if (last == INT32_MAX)
//         cout << "unconnected" << endl;
//     else
//         cout << minDist[n];

//     return 0;
// }

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

//SPAF + 判断负环
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
    vector<int> count(n + 1, 0);
    queue<int> que;
    vector<bool> is_in_queue(n + 1, false);
    int start = 1;
    is_in_queue[start] = true;
    count[start]++;
    dist[start] = 0;
    que.push(start);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        is_in_queue[cur] = false;

        for (auto [v, w] : adj[cur]) {
            if (dist[v] > dist[cur] + w) {
                count[v]++;
                dist[v] = dist[cur] + w;
                if (count[v] >= n) {
                    cout << "circle" << endl;
                    return 0;
                }
            }
            if (!is_in_queue[v]) {
                is_in_queue[v] = true;
                que.push(v);
            }
        }
    }

    if (dist[n] == INT32_MAX) {
        cout << "unconnected" << endl;
    } else {
        cout << dist[n] << endl;
    }
    return 0;
}