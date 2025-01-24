#include<iostream>
#include<vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int k=0;k<T;k++){
        int m,flag=0;
        cin>>m;
        vector<int> v(m);
        for(int i=0;i<m;i++){
            cin>>v[i];
        }
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(v[i]%v[j]==0){
                    flag++;
                }
            }
        }
        cout<<flag<<endl;
    }
    return 0;
}