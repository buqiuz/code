#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> fa;

public:
    int find(int u) { return fa[u] == u ? u : (fa[u] = find(fa[u])); }
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        fa[u] = v;
    }

    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    UnionFind(int n) : fa(n + 1) {
        for (int i = 0; i <= n; i++)
            fa[i] = i;
    }
};

struct edge {
    int l, r, val;
};

int main() {
    int v, e;
    cin >> v >> e;

    vector<edge> edges(e);
    for (int i = 0; i < e; i++) {
        cin >> edges[i].l >> edges[i].r >> edges[i].val;
    }

    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) { return a.val < b.val; });

    int ret = 0;

    UnionFind unionFind(v);
    for (auto [l, r, val] : edges) {
        if (!unionFind.same(l, r)) {
            ret += val;
            unionFind.join(l, r);
        }
    }
    cout << ret << endl;
    return 0;
}