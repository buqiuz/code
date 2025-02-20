#include <bits/stdc++.h>
using namespace std;

class MySet {
    vector<int> fa;

public:
    MySet(int n) : fa(n + 1) {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }

    int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        fa[u] = v;
        return true;
    }
};

int main() {

    int n;
    cin >> n;
    MySet mySet(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (!mySet.join(u, v))
            cout << u << " " << v;
    }
    return 0;
}