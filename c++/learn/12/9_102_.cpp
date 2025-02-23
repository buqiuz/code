#include <bits/stdc++.h>
using namespace std;

int dir[4][2]{-1, 0, 1, 0, 0, -1, 0, 1};
void dfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || yy < 0 || xx >= grid.size() || yy >= grid[0].size() || visited[xx][yy] == true ||
            grid[xx][yy] == 0)
            continue;

        visited[xx][yy] = true;
        dfs(grid, visited, xx, yy);
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
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) {
            visited[i][0] = true;
            dfs(grid, visited, i, 0);
        }
        if (grid[i][m - 1] == 1) {
            visited[i][m - 1] = true;
            dfs(grid, visited, i, m - 1);
        }
    }

    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1) {
            visited[0][j] = true;
            dfs(grid, visited, 0, j);
        }
        if (grid[n - 1][j] == 1) {
            visited[n - 1][j] = true;
            dfs(grid, visited, n - 1, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == false && grid[i][j] == 1)
                grid[i][j] = 0;
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}