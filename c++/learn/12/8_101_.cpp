#include <bits/stdc++.h>
using namespace std;

int dir[4][2]{-1, 0, 1, 0, 0, -1, 0, 1};
void bfs(vector<vector<int>> &grid, int x, int y) {
    queue<pair<int, int>> q;
    grid[x][y] = 0;
    q.push({x, y});
    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size() || grid[nextx][nexty] == 0)
                continue;
            grid[nextx][nexty] = 0;
            q.push({nextx, nexty});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1)
            bfs(grid, i, 0);
        if (grid[i][m - 1] == 1)
            bfs(grid, i, m - 1);
    }

    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1)
            bfs(grid, 0, j);
        if (grid[n - 1][j] == 1)
            bfs(grid, n - 1, j);
    }

    int ret = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1)
                ret++;
        }
    }
    cout << ret;
    return 0;
}