#include <bits/stdc++.h>
using namespace std;
// // 合并两个有序数组
// void merge(vector<int>& arr, int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     // 创建临时数组
//     vector<int> L(n1);
//     vector<int> R(n2);

//     // 将数据复制到临时数组 L 和 R
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

//     // 合并临时数组到原数组 arr
//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     // 处理剩余元素
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// 自底向上归并排序

void show(vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl;
    
}
void mergeSort(vector<int>& arr) {
    int n = arr.size();

    for (int currSize = 1; currSize <= n - 1; currSize *= 2) {
        for (int left = 0; left < n - 1; left += 2 * currSize) {
            int mid = min(left + currSize - 1, n - 1);
            int right = min(left + 2 * currSize - 1, n - 1);
            inplace_merge(arr.begin()+left,arr.begin()+mid+1,arr.begin()+right+1);
            show(arr);
        }
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7,3};

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    mergeSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
