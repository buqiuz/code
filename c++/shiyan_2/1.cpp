#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;

struct Date {
    int id, v;
    Date() {}
    Date(int ID, int V) : id(ID), v(V) {}
};

int n;
int road[MAXN];
priority_queue<int, vector<int>, greater<int>> q[10];

bool check() {
    for (int i = 1; i <= 4; i++) {
        if (!q[i].empty()) {
            return true;
        }
    }
    return false;
}

void processQueue(int& step, int l, int r) {
    while (check()) {
        while (!q[3].empty() && (q[4].empty() == l || (q[3].top() < q[4].top()))) {
            road[++step] = q[3].top();
            q[3].pop();
        }
        if (!q[4].empty()) {
            road[++step] = q[4].top();
            q[4].pop();
        }
        while (!q[2].empty() && (q[1].empty() == r || (q[2].top() < q[1].top()))) {
            road[++step] = q[2].top();
            q[2].pop();
        }
        if (!q[1].empty()) {
            road[++step] = q[1].top();
            q[1].pop();
        }
    }
}

void solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a, v;
        cin >> a >> v;
        q[a].push(v);
        ans += (a == 1) ? 2 : ((a == 4) ? -2 : ((a == 5 || a == 7) ? 1 : ((a == 6 || a == 8) ? -1 : 0)));
    }

    if (ans != 0) {
        cout << "-1";
        return;
    }

    int step = 0;
    if (!q[5].empty()) {
        road[++step] = q[5].top();
        q[5].pop();
        processQueue(step, 1, 0);
        road[++step] = (q[7].empty()) ? q[8].top() : q[7].top();
    } else {
        road[++step] = q[6].top();
        q[6].pop();
        processQueue(step, 0, 1);
        road[++step] = (q[7].empty()) ? q[8].top() : q[7].top();
    }

    for (int i = 1; i <= n; i++) {
        cout << road[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    solve();

    return 0;
}
