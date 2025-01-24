#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int> &arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i-gap; j >= 0 && arr[j ] > temp; j -= gap) {
                arr[j+gap] = arr[j];
            }
            arr[j+gap] = temp;
        }
    }
}

int main() {
    vector<int> arr = {34 , 12 , 78  ,9  ,23  ,67  ,4 , 45 , 98 , 56 , 7  ,89 , 1 , 32 , 56 , 23  ,44
};
    shellSort(arr);

    cout << "排序后的数组：";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
