#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    int x, y, val;
    vector<vector<int>> grid(v + 1, vector<int>(v + 1, INT32_MAX));

    for (int i = 0; i < e; i++) {
        cin >> x >> y >> val;
        grid[x][y] = val;
        grid[y][x] = val;
    }
    // 距离当前节点的距离向量
    vector<int> dist(v + 1, INT32_MAX - 1);

    // 节点
    vector<bool> inTree(v + 1, false);
    // 循环v-1次，才可以将所有节点纳入生成树
    for (int i = 0; i < v - 1; i++) {
        // 找到最距离生成树最近的节点
        int cur = -1;
        int minDist = INT32_MAX;
        for (int j = 1; j <= v; j++) {
            if (!inTree[j] && dist[j] < minDist) {
                cur = j;
                minDist = dist[j];
            }
        }

        // 加入节点
        inTree[cur] = true;
        // 更新距离向量
        for (int j = 1; j <= v; j++) {
            if (!inTree[j] && grid[cur][j] < dist[j])
                dist[j] = grid[cur][j];
        }
    }

    int ret = 0;
    for (int i = 2; i <= v; i++) {
        ret += dist[i];
    }

    cout << ret << endl;

    return 0;
}