#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            // 交换arr[i]和arr[minIndex]
            // int temp = arr[i];
            // arr[i] = arr[minIndex];
            // arr[minIndex] = temp;
            swap(arr[i],arr[minIndex]);
        }
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr);

    cout << "排序后的数组：";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
