#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>


using namespace std;
void show(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i!=v.size()-1){
            cout<<" ";
        }
    }
    cout<<endl;
}

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> v;
    
    for(int i=0;i<K;i++){
        int a;
        cin>>a;
        if (a==1)
        {   
            int b;
            cin>>b;
            v.push_back(b);
            push_heap(v.begin(),v.end(),greater<int>());
            show(v);
        }
        if (a==-1)
        {
            pop_heap(v.begin(),v.end(),greater<int>());
            // v.pop_back();
            show(v);
        }  
    }
    int M;
    cin>>M;
    vector<int> vec(M);
    for (int i = 0; i < M; i++)
    {
        cin>>vec[i];
    }
    make_heap(vec.begin(),vec.end(),greater<int>());
    show(vec);
    return 0;
}
