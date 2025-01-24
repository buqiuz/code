#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    long long  n,m;
    cin>>n>>m;
    vector<long long> v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(long long i=v.size()-1;i>=0&&m>0;i--,m--){
        cout<<v[i];
        if(m!=1){
            cout<<" ";
        }
    }
    return 0;
}