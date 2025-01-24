#include <iostream>
#include <vector>

using namespace std; // 使用命名空间 std

void merge(vector<int> &a, vector<int> &tem, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int pos = p;

    while (i <= q && j <= r) {
        if (a[i] < a[j])
            tem[pos++] = a[i++];
        else
            tem[pos++] = a[j++];
    }

    while (i <= q)
        tem[pos++] = a[i++];

    while (j <= r)
        tem[pos++] = a[j++];

    while (p <= r) {
        a[p] = tem[p];
        p++;
    }
}

void print(const vector<int> &s, int n) {
    for (int t = 0; t < n; t++) {
        cout << s[t];
        if (t == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}

void msort(vector<int> &a, vector<int> &tem, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        msort(a, tem, p, q);
        msort(a, tem, q + 1, r);
        merge(a, tem, p, q, r);
        print(a, a.size());
    }
}

void merge_sort(vector<int> &a, int n) {
    vector<int> tem(n);
    msort(a, tem, 0, n - 1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        merge_sort(a, n);
    }
    return 0;
}