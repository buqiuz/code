#include<iostream>
#include<stack>
#include<string>
#include<queue>
using namespace std;

int main() {
    int M;
    queue<long long int> q;
    cin>>M;
    string s;
    for(int i=0;i<M;i++){
        cin>>s;
        if(s=="push"){
            int a;
            cin>>a;
            q.push(a);
        }
        if(s=="empty"){
            if(!q.empty()){
                cout<<"NO"<<endl;
            }
            else cout<<"YES"<<endl;
        }
        if(s=="pop"){
            q.pop();
        }
        if(s=="query"){
            cout<<q.front()<<endl;
        }
    }

    return 0;
}
