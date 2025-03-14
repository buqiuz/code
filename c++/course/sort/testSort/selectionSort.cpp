#include<iostream>
#include<vector>

using namespace std;
void selectionSort (vector<int> &v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i;j<n;j++) {
            if(v[j]<v[minIndex]){
                minIndex=j;
            }
        }
        swap(v[i],v[minIndex]);
    }
}
int main(){
    vector<int> v{2,5,13,4,6,8,7};
    selectionSort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}