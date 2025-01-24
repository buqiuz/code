#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int distance, const vector<int>& v, int m) {
    int count = 1;
    int last = v[0];

    for (int i = 1; i < v.size(); ++i) {
        if (v[i] - last >= distance) {
            last = v[i];
            count++;
            if (count == m)
                return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = v[n - 1] - v[0];
    int result = 0;

    while (left <= right) {
        int mid = (right + left) / 2;

        if (check(mid, v, m)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}
