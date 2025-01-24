#include<iostream>
#include<vector>

using namespace std;

int partion(vector<int> &v, int low, int high) {
    int i = low, j = high;
    int pivot = v[(low + high) /2];
    while (1) {
        while (v[i] < pivot) {
            i++;
        }
        while (v[j] > pivot) {
            j--;
        }
        if (i >= j) {
            return i;
        }
        swap(v[i], v[j]);
        i++;
        j--;
    }
}

void quickSort(vector<int> &v, int low, int high) {
    if (low < high) { // Add this condition to prevent sorting when low >= high
        int mid = partion(v, low, high);
        quickSort(v, low, mid - 1);
        quickSort(v, mid+1, high);
    }
}

int main() {
    vector<int> v{10, 5, 13, 4, 6, 8, 7,1,98,3,5};
    quickSort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
