#include <bits/stdc++.h>
using namespace std;

int dir[4][2]{0, 1, 0, -1, -1, 0, 1, 0};
void dfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
            continue; // 越界了，直接跳过
        if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {
            visited[nextx][nexty] = true;
            dfs(grid, visited, nextx, nexty);
        }
    }
}

int main() {

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                visited[i][j] = true;
                ret++;
                dfs(grid, visited, i, j);
            }
        }
    }

    cout << ret << endl;
    return 0;
}