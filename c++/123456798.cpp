#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y;
    int g, h, f;
    Node *parent;
    Node(int x, int y, int g, int h, Node *parent = nullptr) : x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}
    bool operator<(const Node &k) const { return f > k.f; }
};

int CalcEurler(int x1, int y1, int x2, int y2) { return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1); }

vector<pair<int, int>> dir = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
// vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 全局变量定义（必须与声明一致）
// int moves[1001][1001] = {0};

int Astar(int startX, int startY, int endX, int endY) {
    // static int moves[1001][1001] = {0}; // 如果在这定义的话，会导致stack溢出,加上static就会定义在全局变量区，不会溢出
    // static vector<vector<int>> moves(1001, vector<int>(1001, 0));
    // 堆上分配，不会溢出但是会超时,可以加static，然后用fill函数初始化，略慢于int数组，因为vector是动态分配的，在堆上
    // memset(moves, 0, sizeof(moves)); // 正确清空数组
    // for (auto &row : moves) {
    //     fill(row.begin(), row.end(), 0);
    // }

    priority_queue<Node> que;
    int dist = CalcEurler(startX, startY, endX, endY);
    que.push({startX, startY, 0, dist});
    while (!que.empty()) {
        Node cur = que.top();
        que.pop();
        if (cur.x == endX && cur.y == endY)
            return cur.g / 5;
        for (auto [dx, dy] : dir) {
            int xx = cur.x + dx;
            int yy = cur.y + dy;
            if (xx < 1 || xx > 1000 || yy < 1 || yy > 1000)
                continue;
            // if (moves[xx][yy] == 0) {
            // moves[xx][yy] = moves[cur.x][cur.y] + 1;
            int curDist = CalcEurler(xx, yy, endX, endY);
            que.push({xx, yy, cur.g + 5, curDist});
            // }
        }
    }
    return -1;
}

int main() {
    int n, startX, startY, endX, endY;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> startX >> startY >> endX >> endY;
        cout << Astar(startX, startY, endX, endY) << endl;
    }
    return 0;
}