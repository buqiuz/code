#include<iostream>
#include<vector>

using namespace std;
void insertionSort(vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        int temp = v[i];
        int j;
        for (j = i - 1; j >= 0 && v[j] > temp; j--) {
            v[j + 1] = v[j];
        }
        v[j + 1] = temp;
    }
}
 
int main(){
    vector<int> v{10,5,13,4,6,8,7};
    insertionSort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}