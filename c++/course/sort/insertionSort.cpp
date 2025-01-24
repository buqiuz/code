#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j ;
        for ( j = i-1; j >=0&&arr[j]>key; j--)
        {
            arr[j+1]=arr[j];
        }
        

        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {34 , 12 , 78  ,9  ,23  ,67  ,4 , 45 , 98 , 56 , 7  ,89 , 1 , 32 , 56 , 23  ,44};
    insertionSort(arr);

    cout << "排序后的数组：";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
