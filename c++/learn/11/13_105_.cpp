#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto x : graph[cur]) {
            if (visited[x])
                continue;

            visited[x] = true;
            q.push(x);
        }
    }

    for (int i = 1; i < visited.size(); i++) {
        if (!visited[i])
            return false;
    }
    return true;
}

int main() {

    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < k; i++) {
        int cur, next;
        cin >> cur >> next;
        graph[cur].push_back(next);
    }

    int ret = bfs(graph, 1) ? 1 : -1;
    cout << ret;
    return 0;
}