#include <bits/stdc++.h>

using namespace std;

// 初版
int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    vector<int> weight(M);
    vector<int> value(M);
    for (auto &x : weight) {
        cin >> x;
    }
    for (auto &x : value) {
        cin >> x;
    }

    vector<vector<int>> dp(M, vector<int>(N + 1));

    for (int i = 0; i < M; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < N + 1; i++) {
        if (i >= weight[0])
            dp[0][i] = value[0];
        else
            dp[0][i] = 0;
    }

    for (int i = 1; i < weight.size(); i++) {
        for (int j = 1; j < N + 1; j++) {
            if (j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[M - 1][N] << endl;
    return 0;
}

// 精简版
int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    vector<int> weight(M);
    vector<int> value(M);
    for (auto &x : weight) {
        cin >> x;
    }
    for (auto &x : value) {
        cin >> x;
    }

    vector<vector<int>> dp(M, vector<int>(N + 1, 0));

    for (int i = weight[0]; i < N + 1; i++) {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < weight.size(); i++) {
        for (int j = 1; j < N + 1; j++) {
            if (j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[M - 1][N] << endl;
    return 0;
}

// 精简版
#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    vector<int> weight(M);
    vector<int> value(M);

    for (auto &x : weight) {
        cin >> x;
    }
    for (auto &x : value) {
        cin >> x;
    }

    vector<int> dp(N + 1, 0);

    for (int i = 0; i < M; i++) {
        for (int j = N; j >= 0; j--) {
            if (j >= weight[i])
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[N] << endl;
    return 0;
}