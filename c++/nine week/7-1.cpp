#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
struct stu
{
    int id;
    int a,b;
};

bool cmp (stu a,stu b){
    if(a.a>b.a)
    return 1;
    else if(a.a==b.a){
        if(a.b>b.b){
            return 1;
        }
        else if(a.b==b.b){
            if(a.id<b.id){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<stu> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].id>>v[i].a>>v[i].b;
    }
    sort(v.begin(),v.end(),cmp);
    for( int i=0;i<n;i++){
        cout<<v[i].id<<endl;
    }
    return 0;
}