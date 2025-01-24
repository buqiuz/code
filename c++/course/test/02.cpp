#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

int partion(vector<int> &v,int low,int high){
    int key=v[low];
    int i=low,j=high;
    while (i<j)
    {
        while (i<j&&v[j]>=key)
        {
            j--;
        }
        while (i<j&&v[i]<=key)
        {
            i++;
        }
        swap(v[i],v[j]);
        
    }
    swap(v[low],v[i]);
    return i;
    
}

void qiuck_sort(vector<int> &v,int low,int high){
    if(low<high){
        int pivot=partion(v,low,high);
        qiuck_sort(v,low,pivot-1);
        qiuck_sort(v,pivot+1,high);
    }
}

void merge(vector<int>& v,int low,int mid,int high){
    vector<int>v1(v.begin()+low,v.begin()+mid+1);
    vector<int>v2(v.begin()+mid+1,v.begin()+high+1);
    int i=0,j=0,k=low;
    while (i<v1.size()&&j<v2.size())
    {
        if(v1[i]<v2[j])
        v[k++]=v1[i++];
        else
        v[k++]=v2[j++];
    }while (i<v1.size())
    {
        v[k++]=v1[i++];
    }
    while (j<v2.size())
    {
        v[k++]=v2[j++];
    }
    
}
void merge_sort(vector<int>& v,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(v,low,mid);
        merge_sort(v,mid+1,high);
        merge(v,low,mid,high);
    }
}
void show(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

void insertSort(vector<int>& v){
    for(int i=1;i<v.size();i++){
        int temp=v[i];
        int j;
        for( j=i-1;j>=0&&v[j]>temp;j--){
            v[j+1]=v[j];
        }
        v[j+1]=temp;
    }
}

int binarySearch(vector<int> &v,int key,int low,int high){
    int mid;
    while (low<high)
    {
        mid=(low+high)/2;
        if(v[mid]==key)
        return mid;
        else if (v[mid]<key)
        {
            low=mid+1;
        }
        else
            high =mid-1;
    }
    
}
int main(){
    vector<int> v;
    srand((int)time(0));
    int n = 50;
    while(n--)
	v.push_back(rand() % 100 + 1);
    show(v);

    // merge_sort(v, 0, v.size() - 1);
    insertSort(v);
    cout<<endl<<endl;
    show(v);

    /* 作者 Amαdeus */

    return 0;
}