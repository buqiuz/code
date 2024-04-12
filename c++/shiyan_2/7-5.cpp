#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;

struct date {
    int id, v;
    bool vis;
    date() {}
    date(int ID, int V) {
        vis = 0, id = ID, v = V;
    }
};

int n;
int map[MAXN];
priority_queue<int, vector<int>, greater<int>> q[10];

bool check() {
    bool flag = 0;
    for (int i = 1; i <= 4; i++) {
        if (q[i].size()) {
            flag = 1;
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int a, v;
        cin >> a >> v;
        q[a].push(v);
        if (a == 1)
            ret += 2;
        if (a == 4)
            ret -= 2;
        if (a == 5)
            ret++;
        if (a == 6)
            ret--;
        if (a == 7)
            ret++;
        if (a == 8)
            ret--;
    }
    if (ret != 0) {
        cout << "-1";
        return 0;
    }
    if (q[5].size()) {
        int step = 0;
        map[++step] = q[5].top();
        q[5].pop();
        int l, r;
        if (q[7].size()) {
            l = 1;
            r = 0;
        } else {
            l = 0;
            r = 1;
        }
        while (check()) {
            while (q[3].size() && (q[4].size() == l || (q[3].top() < q[4].top()))) {
                map[++step] = q[3].top();
                q[3].pop();
            }
            if (q[4].size()) {
                map[++step] = q[4].top();
                q[4].pop();
            }
            while (q[2].size() && (q[1].size() == r || (q[2].top() < q[1].top()))) {
                map[++step] = q[2].top();
                q[2].pop();
            }
            if (q[1].size()) {
                map[++step] = q[1].top();
                q[1].pop();
            }
        }
        if (q[7].size()) {
            map[++step] = q[7].top();
        } else {
            map[++step] = q[8].top();
        }
    } else {
        int step = 0;
        map[++step] = q[6].top();
        q[6].pop();
        int l, r;
        if (q[7].size()) {
            l = 0;
            r = 1;
        } else {
            l = 1;
            r = 0;
        }
        while (check()) {
            while (q[2].size() && (q[1].size() == l || (q[2].top() < q[1].top()))) {
                map[++step] = q[2].top();
                q[2].pop();
            }
            if (q[1].size()) {
                map[++step] = q[1].top();
                q[1].pop();
            }
            while (q[3].size() && (q[4].size() == r || (q[3].top() < q[4].top()))) {
                map[++step] = q[3].top();
                q[3].pop();
            }
            if (q[4].size()) {
                map[++step] = q[4].top();
                q[4].pop();
            }
        }
        if (q[7].size()) {
            map[++step] = q[7].top();
        } else {
            map[++step] = q[8].top();
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << map[i] ;
        if(i!=n){
            cout<<" ";
        }
    }
    return 0;
}
