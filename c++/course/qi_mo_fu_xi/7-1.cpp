#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    int cnt=1;
    while (n>1)
    {
        cout<<n<<" ";
        if (n&1)//判断奇数    
        {
            n=n*3+1;
            cnt++;
        }else{
            n/=2;
            cnt++;
        } 
    }cout<<1<<endl;
    cout<<"count = "<<cnt;
    
    return 0;
}
