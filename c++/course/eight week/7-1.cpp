#include<iostream>
#include<vector>
using namespace std;

void for_each (vector<int> v){
        for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i!=v.size()-1) cout<<" ";   
    }
    cout<<endl;
}

int main(){
    int N;
    cin>>N;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];  
    }
    for(int i=1;i<N;i++){
        int temp=v[i];
        for(int j=i-1;j>=0;j--){
            if(v[j]>temp) v[j+1]=v[j];
            if(v[j]<temp){  
                v[j+1]=temp;
                break;
            }
            if(v[0]>temp&&j==0) v[0]=temp;

        }
        for_each(v);
    }

    return 0;
}