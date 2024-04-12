#include<iostream>
#include<vector>
#include<list>    
using namespace std;
int main (){
    int n,a;
    long long int total_expenditure=0,total_revenue=0;
    cin>>n;
    list<int> lis;
    for(int i=0;i<n;i++){
        cin>>a;  
        lis.push_back(a);
        if(i!=n-1)total_expenditure+=a;
        for(auto it=lis.begin();it!=lis.end();){
            if(*it<a){
                it=lis.erase(it);//迭代器会失效，所以需要更新迭代器
                total_revenue+=a;
            }else{
                ++it;
            }
        }
        if(i==n-1){
            for(auto it=lis.begin();it!=lis.end();++it){
                if(*it>0){
                    total_revenue+=a;
                }
            }
        }

    }
    cout<<total_revenue-total_expenditure-a<<endl;
    return 0;
}