#include<iostream>
#include<vector>
#include<set>


using namespace std;

bool is_prime(vector<bool> &v,int a){
    for(int i=2;i<v.size();i++){
        int n=2;
        while (n*i<=a)
        {
            v[i*n]=0;
            n++;
        }       
    }
    return 0;
}
long is_factor(vector<bool> &v,int a){
    long b=0;
    for(int i=2;i<v.size();i++){
        if(a%i==0&&v[i]==1){
            v[i]=1;
            b=i;
        }else{
            v[i]=0;
        }
    }
    return b;
}

int main(){
    long a;
    
    cin>>a;
    vector<bool> v(a+1,1);
    v[0]=0;
    v[1]=0;
    is_prime(v,a);
    long b=is_factor(v,a);
    
    for (int i=0;i<v.size();i++){
        if(v[i]==1){
            cout<<i;
            if(i!=b){
                cout<<" ";
            }
        }
    }
    
    return 0;
}