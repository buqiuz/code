#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binarySearch(vector<int> &v,int key,int low,int high){
    int mid;
    while (low<=high)
    {
        mid = low + (high - low) / 2;
        if(v[mid]==key)
        return mid;
        else if (v[mid]<key)
        {
            low=mid+1;
        }
        else
            high =mid-1;
    }
    return -1;
}


vector<int> prime(int n){
    vector<bool> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
    vector<int> v;
    for(int i=0;i<=n;i++){
        if(is_prime[i]){
            v.push_back(i);
        }
    }
    return v;
}

int gcd(int a,int b){
    while (b)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a; 
}
int main(){
    // vector<int> v={1,2,5,10,4,3,6,9,8,15,8,26,649,45};
    // sort(v.begin(),v.end());
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    
    // cout<<binarySearch(v,10,0,v.size()-1);


    // int n;
    // cin>>n;
    // vector<int> v=prime(n);
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i]<<" ";
    // }

    int a,b;
    cin>> a>>b;
    cout<<gcd(a,b);
    return 0;
}