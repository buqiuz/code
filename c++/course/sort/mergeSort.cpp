#include <iostream>
#include <vector>

using namespace std;

// 合并两个有序数组
void merge(vector<int>& arr, int left, int mid, int right) {
    // int n1 = mid - left + 1;
    // int n2 = right - mid;

    vector<int> leftArr(arr.begin()+left,arr.begin()+mid+1);
    vector<int> rightArr(arr.begin()+mid+1,arr.begin()+right+1);

    // 将数据分别拷贝到左右子数组中
    // for (int i = 0; i < n1; i++) {
    //     leftArr[i] = arr[left + i];
    // }

    // for (int j = 0; j < n2; j++) {
    //     rightArr[j] = arr[mid + 1 + j];
    // }

    // 合并两个子数组
    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
            // i++;
        } else {
            arr[k++] = rightArr[j++];
            // j++;
        }
        // k++;
    }

    // 处理剩余元素
    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
        // i++;
        // k++;
    }

    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
        // j++;
        // k++;
    }
}

// 归并排序
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7,45,34,48,96,3,4};

    cout << "原始数组: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "排序后的数组: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
