#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isout(int n, vector<int>& v1, vector<int>& v2) {
    stack<int> st;
    int a = 0;
    int b = 0;

    while (b < n) {
        if (!st.empty() && st.top() == v2[b]) {
            st.pop();
            b++;
        } else if (a < n) {
            st.push(v1[a]);
            a++;
        } else {
            return false;  // 无法匹配
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> v1(n);
        vector<int> v2(n);

        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> v2[i];
        }

        if (isout(n, v1, v2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
