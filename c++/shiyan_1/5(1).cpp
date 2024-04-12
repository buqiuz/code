#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        n--;
        int a, ans = 0;
        cin >> a;
        int v[a + 1] = {0};
        int b[a + 1];

        for (int i = 1; i <= a; i++) {
            cin >> b[i];
        }

        for (int i = a; i >= 1; i--) {
            ans += v[b[i]];
            for (int k = b[i]; k <= a; k += b[i]) {
                v[k]++;
            }
        }

        cout << ans << endl;
    }
}
