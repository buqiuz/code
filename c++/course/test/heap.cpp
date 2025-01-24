#include<iostream>
#include<vector>
#include<algorithm>


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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> v2=v;
    make_heap(v.begin(),v.end(),less<int>());
    show(v);
    make_heap(v2.begin(),v2.end(),greater<int>());
    show(v2);

    return 0;
}


