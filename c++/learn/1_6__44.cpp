#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d",&v[i][j]);
            v[i][m]+=v[i][j];
            v[n][j]+=v[i][j];
        }
    }
    
    vector<int> row(n,0),col(m,0);
    
    row[0]=v[0][m];
    col[0]=v[n][0];
    for (int i = 1; i < n; i++) {
        row[i]=row[i-1]+v[i][m];
    }
    for (int i = 1; i < m; i++) {
        col[i]=col[i-1]+v[n][i];
    }
    
    // 计算最小差值
    int min_difference = INT32_MAX;

    // 处理行分割的最小差值
    for (int i = 0; i < n - 1; i++) {
        min_difference = min(min_difference, abs(row[n - 1] - 2 * row[i]));
    }

    // 处理列分割的最小差值
    for (int i = 0; i < m - 1; i++) {
        min_difference = min(min_difference, abs(col[m - 1] - 2 * col[i]));
    }

    // 输出最小差值
    printf("%d\n", min_difference);
    
    return 0;
}