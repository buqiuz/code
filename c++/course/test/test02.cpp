#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;
int partion(vector<int> &v,int low,int high);

// int partion(vector<int> &v,int low,int high){
//     int pivot=v[low];
//     int i=low,j=high;
//     while (i<j)
//     {
//         while (v[j]>=pivot&&i<j)
//         {
//             j--;
//         }
//         while (v[i]<=pivot&&i<j)
//         {
//             i++;
//         }
//         swap(v[i],v[j]);
//     }
//     swap(v[low],v[i]);
//     return i;
// }

void qiuck_sort(vector<int> &v,int low,int high){
    if(low<high){
        int pivot=partion(v,low,high);
        qiuck_sort(v,low,pivot-1);
        qiuck_sort(v,pivot+1,high);
    }
}

void merge(vector<int> &v,int low ,int mid,int high){
    vector<int> v1(v.begin()+low,v.begin()+mid+1);
    vector<int> v2(v.begin()+mid+1,v.begin()+high+1);

    // int k=low,i=0,j=0;
    // while (i<v1.size()&&j<v2.size())
    // {
    //     if(v1[i]<v2[j]){
    //         v[k++]=v1[i++];
    //     }else{
    //         v[k++]=v2[j++];
    //     }
    // }while (i<v1.size())
    // {
    //     v[k++]=v1[i++];
    // }
    // while (j<v2.size())
    // {
    //     v[k++]=v2[j++];
    // } 
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin()+low);
    
}
void merge_sort(vector<int> &v,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(v,low,mid);
        merge_sort(v,mid+1,high);
        inplace_merge(v.begin()+low,v.begin()+mid+1,v.begin()+high+1);
    }
}
void show(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int partion(vector<int> &v,int low,int high){
    swap(v[low],v[high]);
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
int main(){
    
    vector<int> v;
    srand((int)time(0));
    int n = 50;
    while(n--)
	v.push_back(rand() % 100 + 1);
    show(v);

    merge_sort(v, 0, v.size() - 1);

    cout<<endl<<endl;
    show(v);

    /* 作者 Amαdeus */

    return 0;
}

