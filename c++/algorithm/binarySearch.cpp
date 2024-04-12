#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int binarySearch (vector<int> v,int low,int high,int key){
    int mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(v[mid]==key){
            return mid;
        }else if(v[mid]<key){
            low=mid+1;
        }else
        {
            high=mid-1;
        }
        
    }
    return -1;
}
int main(){
    vector<int> v={1,2,5,9,4,3,6,9,8,15,8,26,649,45};
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    cout<<binarySearch(v,0,v.size()-1,9);
    return 0;
}