#include<iostream>
#include<vector>

using namespace std;
vector<int> prime(int n){
    vector<bool> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    // for (int i = 2; i*i <= n; i++)     //重点 ，从2到√n依次遍历，对于每次的质数，从i^2开始到n，每次+i去除不是质数的数
    // {
    //     if(is_prime[i]){
    //         for(int j=i*i;j<=n;j+=i){
    //             is_prime[j]=false;
    //         }
    //     }
    // }
    for(int i=2;i*i<=n;i++){
        if(is_prime[i]){
            for (int j = i*i; j <= n; j+=i){
                is_prime[j]=false;
            }
        }
    }

    vector<int> temp;
    for(int i=0;i<n+1;i++){
        if(is_prime[i]){
            temp.push_back(i);
        }
    }
    return temp;
}
int main(){
    int n;
    cin>>n;
    vector<int> v=prime(n);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}