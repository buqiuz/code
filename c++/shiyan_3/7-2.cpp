#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binarySearch (vector<int> &v,int a){
    int low=0,high=v.size();
    int mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(v[mid]==a){
            cout<<mid+1;
            return mid;
        }
        if(v[mid]<a){
            low=mid+1;
                       
        }
        if (v[mid]>a) 
        {
            high=mid-1;;
            
        }
        
    }
    cout<<"0";
    return -1;
}



int main(){
    int n;
    while (cin>>n)
    {
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
            
        }
        cout<<endl;
        
        int num;
        cin>>num;
        for(int i=0;i<num;i++){
            int a;
            cin>>a;
            binarySearch(v,a);
            if(i!=num-1)
            cout<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}