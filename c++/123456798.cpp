#include<bits/stdc++.h>
using namespace std;


//初版
int main(){
    int k;
    cin>>k;
    string s,ret;
    cin>>s;
    
    ret+=s.substr(s.size()-k-1,k);
    ret+=s.substr(0,s.size()-k);
    cout<<ret<<endl;
    
    return 0; 
}

#include<bits/stdc++.h>
using namespace std;

//版本一
int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin()+k);
    reverse(s.begin()+k,s.end());
    cout<<s<<endl;
    return 0; 
}