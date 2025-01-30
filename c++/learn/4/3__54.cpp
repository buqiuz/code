#include<bits/stdc++.h>
using namespace std;

int main (){
    string s,ret;
    cin>>s;
    for(auto x:s){
        if(isdigit(x)){
            ret+="number";
        }
        else{
            ret+=x;
        }
    }
    cout<<ret<<endl;
    return 0;
}