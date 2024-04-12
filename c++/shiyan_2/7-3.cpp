#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool cmp(int a,int b){
    if(a>b){
        return 1;
    }
    return 0;
}

int main(){
    int n,valid=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),cmp);
    if(n<3){
        cout<<"小棍的个数不能组成三角形"<<endl;
    }
    else {
        for(int i=0;i<n-3;i++){
            if(v[i+1]+v[i+2]>v[i]){
                cout<<"最大三角形的周长是"<<v[i]+v[i+1]+v[i+2]<<endl;
                cout<<"组成最大三角形的三条边是"<<v[i+2]<<","<<v[i+1]<<","<<v[i]<<endl;
                valid=1;
                break;
            }
        }
        if(!valid){
            cout<<"没有找到能组成三角形的小棍"<<endl;
        }

    }


    return 0;
}