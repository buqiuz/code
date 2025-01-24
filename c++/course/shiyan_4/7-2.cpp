#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    map<string,int> m;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        int num;
        cin>>num;
        if(num<500){
            m[s]+=500;
            
        }
        else{
            m[s]=num;
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(m[s]!=0){
            cout<<m[s]<<endl;
        }else{
            cout<<"No Info"<<endl;
        }
    }
    return 0;
}