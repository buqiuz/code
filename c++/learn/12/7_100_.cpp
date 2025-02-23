#include <bits/stdc++.h>
using namespace std;

int dir[4][2]{-1, 0, 1, 0, 0, -1, 0, 1};
int bfs(vector<vector<int>> &grid, int x, int y) {
    queue<pair<int, int>> q;
    grid[x][y] = 0;
    q.push({x, y});
    int ret = 0;
    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        ret++;
        for (int i = 0; i < 4; i++) {
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size() || grid[nextx][nexty] == 0)
                continue;
            grid[nextx][nexty] = 0;
            q.push({nextx, nexty});
        }
    }
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) {
                ret = max(ret, bfs(grid, i, j));
            }
        }
    }
    cout << ret;
    return 0;
}