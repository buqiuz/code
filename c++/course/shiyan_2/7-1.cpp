#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &a, int left, int right){
    int i = left;
    int j = right;
    int key = a[left];

    while(i != j){
        while(i < j && a[j] >= key)      	 //向左找到小于基准值的值的下标
            j--;
        while(i < j && a[i] <= key)      	 //向右找到大于基准值的值的下标
            i++;
	swap(a[i], a[j]);
	}
    /*   i等于j时跳出循环 当前基准值此时在下标为i的位置(合适的位置)   */
    swap(a[left], a[i]);
        for (int i= 0; i < a.size(); i++) {
        cout << a[i] << " ";
        }
        cout<<endl;              //最左边的元素变为处于当前合适位置的元素,把基准值放在合适位置                                                 
    return i;                                  //返回合适位置(i,j都可以)
}


void quickSort(vector<int> &arr, int low, int high) {

        if(low<=high){
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
        }
    
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n) ;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    quickSort(arr, 0, n - 1);

    // cout << "排序后的数组：";
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }

    return 0;
}
