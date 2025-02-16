#include <bits/stdc++.h>
using namespace std;

// 超时,且其中26行比较时不加显示转换会出现逻辑错误
int dir[4][2]{1, 0, 0, 1, -1, 0, 0, -1};
bool dfs_1(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || yy < 0)
            return true;
        if (xx >= grid.size() || yy >= grid[0].size() || visited[xx][yy] == true || grid[xx][yy] > grid[x][y])
            continue;

        visited[xx][yy] = true;
        if (dfs_1(grid, visited, xx, yy))
            return true;
    }
    return false;
}

bool dfs_2(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx >= (int)grid.size() || yy >= (int)grid[0].size())
            return true;
        if (xx < 0 || yy < 0 || visited[xx][yy] == true || grid[xx][yy] > grid[x][y])
            continue;

        visited[xx][yy] = true;
        if (dfs_2(grid, visited, xx, yy))
            return true;
    }
    return false;
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

    vector<vector<int>> ret(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[i][j] = true;

            if (dfs_1(grid, visited, i, j))
                ret[i][j]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[i][j] = true;

            if (dfs_2(grid, visited, i, j))
                ret[i][j]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ret[i][j] == 2)
                cout << i << " " << j << endl;
        }
    }
    return 0;
}

// 版本1
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
    if (visited[x][y])
        return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
            continue;
        if (grid[x][y] > grid[nextx][nexty])
            continue; // 注意：这里是从低向高遍历

        dfs(grid, visited, nextx, nexty);
    }
    return;
}

int main() {

    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    // 标记从第一组边界上的节点出发，可以遍历的节点
    vector<vector<bool>> firstBorder(n, vector<bool>(m, false));

    // 标记从第一组边界上的节点出发，可以遍历的节点
    vector<vector<bool>> secondBorder(n, vector<bool>(m, false));

    // 从最上和最下行的节点出发，向高处遍历
    for (int i = 0; i < n; i++) {
        dfs(grid, firstBorder, i, 0);      // 遍历最左列，接触第一组边界
        dfs(grid, secondBorder, i, m - 1); // 遍历最右列，接触第二组边界
    }

    // 从最左和最右列的节点出发，向高处遍历
    for (int j = 0; j < m; j++) {
        dfs(grid, firstBorder, 0, j);      // 遍历最上行，接触第一组边界
        dfs(grid, secondBorder, n - 1, j); // 遍历最下行，接触第二组边界
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 如果这个节点，从第一组边界和第二组边界出发都遍历过，就是结果
            if (firstBorder[i][j] && secondBorder[i][j])
                cout << i << " " << j << endl;
            ;
        }
    }
}
