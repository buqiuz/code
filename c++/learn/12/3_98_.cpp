#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ret;
vector<int> path;

void dfs(int &n, vector<list<int>> &graph, int node) {
    if (node == n) {
        ret.push_back(path);
        return;
    }

    for (auto x : graph[node]) {
        path.push_back(x);
        dfs(n, graph, x);
        path.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<list<int>> graph(N + 1);

    while (M--) {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
    }

    path.push_back(1);

    dfs(N, graph, 1);

    if (ret.empty())
        cout << "-1" << endl;

    for (auto x : ret) {
        for (auto y : x) {
            if (y != x.front())
                cout << " ";
            cout << y;
        }
        cout << endl;
    }

    return 0;
}

//第二次写
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ret;
vector<int> path;

void dfs(vector<vector<int>> &adj, int node, int &n) {
    if (node == n) {
        ret.push_back(path);
        return;
    }

    for (auto x : adj[node]) {
        path.push_back(x);
        dfs(adj, x, n);
        path.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    path.push_back(1);
    dfs(adj, 1, n);

    if (ret.empty()) {
        cout << -1;
        return 0;
    }

    for (auto x : ret) {
        for (auto y : x) {
            if (y != x.front())
                cout << " ";
            cout << y;
        }
        cout << endl;
    }
    return 0;
}