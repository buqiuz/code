#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < n + 1; j++) {
        for (int i = 1; i <= m; i++) {
            if (j >= i)
                dp[j] += dp[j - i];
        }
    }
    cout << dp[n] << endl;
    return 0;
}