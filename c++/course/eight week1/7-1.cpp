#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)    {
        cin>>v[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        int valid=0;
        for (int j = 0; j < n-i-1; j++)
        {
            if(v[j]>v[j+1]){
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
                valid=1;
            }
        }
        if(valid){
            for(int j=0;j<n;j++){
            cout<<v[j];
            if(j!=n-1)
            {
                cout<<" ";
            }
        }
        cout<<endl;
        }

    }
    
    
    return 0;
}