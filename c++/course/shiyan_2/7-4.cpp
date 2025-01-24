#include<iostream>
#include<vector>

using namespace std;

int valid=0;

void insertionSort(vector<int> &arr,vector<int> v) {
    int flag=0;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j ;
        for ( j = i-1; j >=0&&arr[j]>key; j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j + 1] = key;
        if(arr==v){
        valid=1;
        flag=i;
        }
        if(i==flag+1){
            cout<<"Insertion Sort"<<endl;
            for(int k=0;k<n;k++){
                cout<<v[k]<<" ";
            }
        }
    }

}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // 将数据分别拷贝到左右子数组中
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // 合并两个子数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
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
    while (i < n1) {
        arr[k++] = leftArr[i++];
        // i++;
        // k++;
    }

    while (j < n2) {
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
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> v1=v;
    insertionSort(v,v1);

    return 0;
}