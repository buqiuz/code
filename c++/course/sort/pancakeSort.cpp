#include <iostream>
#include <vector>

using namespace std;

// 翻转操作
void flip(vector<int> &arr, int k) {
    int i = 0;
    while (i < k) {
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
        i++;
        k--;
    }
}

// 寻找最大的煎饼在 arr 中的位置
int findMaxIndex(vector<int> &arr, int n) {
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// 煎饼排序
void pancakeSort(vector<int> &arr) {
    int n = arr.size();
    for (int currSize = n; currSize > 1; currSize--) {
        int maxIndex = findMaxIndex(arr, currSize - 1);

        if (maxIndex != currSize - 1) {
            if (maxIndex != 0) {
                flip(arr, maxIndex);
            }
            flip(arr, currSize - 1);
        }
    }
}

int main() {
    vector<int> arr = {3, 2, 4, 1};
    cout << "未排序的煎饼: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    pancakeSort(arr);

    cout << "\n排序后的煎饼: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
