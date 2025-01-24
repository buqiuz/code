#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<bool> v(p, false);
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        int pos = num % p;
        int k=0;
        while (v[pos]) {
            k++;
            pos = (pos + k) % p;  // 使用取模运算确保 pos 在合法范围内
        }
        v[pos] = true;
        cout << pos;
        if (i != n - 1) {
            cout << " ";
        }
    }
    return 0;
}