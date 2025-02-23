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