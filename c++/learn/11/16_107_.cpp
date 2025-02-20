#include <bits/stdc++.h>
using namespace std;

class MySet {
    vector<int> fa;

public:
    int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        fa[u] = v;
    }
    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    MySet(int n) : fa(n + 1) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    MySet myset(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        myset.join(u, v);
    }

    int sourse, destination;
    cin >> sourse >> destination;

    cout << myset.isSame(sourse, destination) << endl;
    return 0;
}