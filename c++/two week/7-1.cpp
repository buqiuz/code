#include<iostream>
using namespace std;

int main(){
    int n,flag=1;
    cin>>n;//n居然可以为1，然年格式错误
    
    if(n==1){
        cout<<n<<endl;
        cout<<"count = "<<1;
    }else{
        cout<<n<<" ";
    while(n!=1){
        if(n%2==0){
            n/=2;
            if(n==1){
                cout<<n;
            }else{
                cout<<n<<" ";
            }
            
            flag++;
        }else{
            n=n*3+1;
            if(n==1){
                cout<<n;
            }else{
                cout<<n<<" ";
            }
            flag++;
        }

    }
    cout<<endl;
    cout<<"count = "<<flag;
    }
    return 0;
}