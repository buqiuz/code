#include <bits/stdc++.h>
using namespace std;

int dir[4][2]{1, 0, 0, 1, -1, 0, 0, -1};
void dfs(vector<vector<int>> &grid, int x, int y, int &key, int &size) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        int n = grid.size();
        int m = grid[0].size();
        if (xx < 0 || yy < 0 || xx >= n || yy >= m || grid[xx][yy] == 0 || grid[xx][yy] == key)
            continue;
        grid[xx][yy] = key;
        size++;
        dfs(grid, xx, yy, key, size);
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
    int key = 2;
    unordered_map<int, int> square;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = key;
                int size = 1;
                dfs(grid, i, j, key, size);
                square[key++] = size;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 0) {
                int curSize = 0;
                set<int> s; // use set to avoid duplicate

                for (int k = 0; k < 4; k++) {
                    int xx = i + dir[k][0];
                    int yy = j + dir[k][1];
                    if (xx < 0 || yy < 0 || xx >= n || yy >= m)
                        continue;
                    int key = grid[xx][yy];
                    if (key != 0)
                        s.insert(key);
                }

                for (auto x : s) {
                    curSize += square[x];
                }

                ret = max(ret, curSize + 1);
            }
        }
    }

    ret = key == 3 ? square[2] : ret; // if there is only one island, return the size of the island
    cout << ret;

    return 0;
}