#include<iostream>
#include<vector>    
using namespace std;
int main (){
    int n,total_expenditure=0,total_revenue=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){  
        cin>>v[i];
        if(i!=n-1)total_expenditure+=v[i];
        for(int j=0;j<i;j++){
            if(v[j]<v[i]&&v[j]>0){
                v[j]=0;
                total_revenue+=v[i];    
            }
        }
        if(i==n-1){
            for(int j=0;j<n-1;j++){
                if(v[j]>0){
                    v[j]=0;
                    total_revenue+=v[i];
                }
            }
        }

    }
    cout<<total_revenue-total_expenditure<<endl;
    return 0;
}