#include<iostream>
#include<vector>

using namespace std;
void for_each (vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void shellSort(vector<int> &v) {
    int n=v.size();
    for( int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=v[i];
            int j;
            for(j=i-gap;j>=0&&v[j]>temp;j-=gap){
                v[j+gap]=v[j];

            }
            v[j+gap]=temp;
        }
        for_each(v);
    }
}

int main(){
    vector<int> v{10,5,13,4,6,8,7};
    shellSort(v);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    return 0;
}