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

// 第二次写
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs(vector<vector<int>> &grid, int x, int y) {
    queue<pair<int, int>> que;
    grid[x][y] = 0;
    que.push({x, y});
    while (!que.empty()) {
        auto [cur_x, cur_y] = que.front();
        que.pop();
        for (auto [dx, dy] : dir) {
            int xx = cur_x + dx;
            int yy = cur_y + dy;
            if (xx < 0 || yy < 0 || xx >= grid.size() || yy >= grid[0].size() || grid[xx][yy] == 0)
                continue;
            grid[xx][yy] = 0;
            que.push({xx, yy});
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

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                ret++;
                bfs(grid, i, j);
            }
        }
    }
    cout << ret;

    return 0;
}