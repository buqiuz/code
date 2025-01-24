#include<iostream>
#include<vector>

using namespace std;
void merge (vector<int> &v,int low,int mid,int hign){
    int n1=mid-low+1;//前一个数组大一些
    int n2=hign-mid;
    vector<int> v1(n1),v2(n2);
    for(int i=0;i<n1;i++){
        v1[i]=v[i+low];//i+low
    }
    for(int i=0;i<n2;i++){
        v2[i]=v[i+mid+1];//i+mid+1；
    }
    int i=0,j=0;
    int k=low;//用k记录；
    while(i<n1&&j<n2){
        if(v1[i]<v2[j]){
            v[k++]=v1[i++];

        }
        else{
            v[k++]=v2[j++];

        }
    }
    while(i<n1){
        v[k++]=v1[i++];
    }
    while(j<n2){
        v[k++]=v2[j++];
    }
    
}
void mergeSort(vector<int>& v,int low,int hign){
    if(low<hign){
        int mid=(low+hign)/2;
        mergeSort(v,low,mid);
        mergeSort(v,mid+1,hign);
        merge(v,low,mid,hign);
    }
}
int main(){
    vector<int> v{10, 5, 13, 4, 6, 8, 7,1,98,3,5,-6};
    mergeSort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}