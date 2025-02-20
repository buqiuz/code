#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> father;

public:
    int find(int u) { return u == father[u] ? u : (father[u] = find(father[u])); }

    void join(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;
        father[u] = v;
    }

    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    UnionFind(int n) : father(n + 1) {
        for (int i = 1; i <= n; i++)
            father[i] = i;
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    vector<int> inDegree(n + 1, 0);
    vector<pair<int, int>> condidates;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ++inDegree[v];
        edges.push_back({u, v});
    }

    for (int i = n - 1; i >= 0; i--) {
        if (inDegree[edges[i].second] == 2) {
            condidates.push_back(edges[i]);
        }
    }

    if (condidates.size() > 0) {
        for (int i = 0; i < 2; i++) {
            UnionFind unionFind(n);
            bool hasCycle = false;
            for (auto x : edges) {
                auto [u, v] = x;
                if (x == condidates[i])
                    continue;
                if (unionFind.same(u, v)) {
                    hasCycle = true;
                    break;
                }
                unionFind.join(u, v);
            }

            if (!hasCycle) {
                cout << condidates[i].first << " " << condidates[i].second;
                return 0;
            }
        }
    }

    if (condidates.size() == 0) {
        UnionFind unionFind(n);
        for (auto [u, v] : edges) {
            if (unionFind.same(u, v)) {
                cout << u << " " << v;
                break;
            }
            unionFind.join(u, v);
        }
    }

    return 0;
}