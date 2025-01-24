#include<iostream>
#include<queue>
#include<vector>

using namespace std;
bool is(vector<queue<int>> &buffer,int a){
    int valid=1;
    for(int i=0;i<buffer.size();i++){
        
        if(buffer[i].back()>a){
            valid=0;
        }
    }
    return valid;
}
int main(){
    int n,b;
    cin>>n;
    vector<int> in(n);
    queue<int> q_out;
    vector<queue<int>> buffer;
    int next=1;


//待重排火车
    for(int i=0;i<n;i++){
       cin>>in[i];
    }
    for(int i=0;i<n;i++){

            if(buffer.empty()||is(buffer,in[i])){
                queue<int> temp;
                temp.push(in[i]);
                buffer.push_back(temp);
                if(in[i]==1){
                    b=buffer.size()-1;
                }
                continue;
            }
            int min=in[i]-buffer[0].back();
            int a=0;
            for(int j=0;j<buffer.size();j++){
                if(in[i]-buffer[j].back()<min){
                    a=j;
                }
            }
            buffer[a].push(in[i]);
            if(in[i]==1){
                b=a;
            }

            
        
    }
    vector<int> v;
    for(int i=0;i<buffer[b].size();i++){
        v.push_back(buffer[b].front());
        buffer[b].pop();

    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<buffer.size();

    return 0;
}