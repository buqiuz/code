#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
struct zu
{
    int a,b,c;
};

int binarySearch (vector<int> &v,zu &z){
    int low=z.b,high=z.c;
    int mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(v[mid]==z.a){
            cout<<mid<<endl;
            return mid;
        }
        if(v[mid]<z.a){
            low=mid+1;
                       
        }
        if (v[mid]>z.a) 
        {
            high=mid-1;;
            
        }
        
    }
    cout<<"-1"<<endl;
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int num=0;
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        zu  z;
        cin>>z.a>>z.b>>z.c;
        binarySearch(v,z);
    }
    
    
    return 0;
}