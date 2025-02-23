#include <bits/stdc++.h>
using namespace std;

int ret = 0;
int dir[4][2]{1, 0, 0, 1, -1, 0, 0, -1};
void dfs(vector<vector<int>> &graph, vector<vector<bool>> &vistied, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];

        if (xx < 0 || yy < 0 || xx >= graph.size() || yy >= graph[0].size()) {
            ret++;
            continue;
        }
        if (graph[xx][yy] == 0)
            ret++;

        if (!vistied[xx][yy] && graph[xx][yy] == 1) {
            vistied[xx][yy] = true;
            dfs(graph, vistied, xx, yy);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    int startX, startY;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                startX = i;
                startY = j;
            }
        }
    }
    vector<vector<bool>> vistied(n, vector<bool>(m, false));
    vistied[startX][startY] = true;
    dfs(graph, vistied, startX, startY);

    cout << ret;

    return 0;
}