#include<iostream>
#include<vector>
#include<algorithm>

struct ball
{
    int a,b;
};
bool cmp(ball a,ball b){
    if(a.a<b.a){
        return 1;
    }
    if(a.a==b.a&&a.b>b.b){
        return 1;
    }
    return 0;
}


using namespace std;
int main(){
    int n;
    cin>>n;
    vector<ball> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].a;
        cin>>v[i].b;
    }
    sort(v.begin(),v.end(),cmp);
    vector<ball> v1,v2;
    v1.insert(v1.end(),v.begin(),v.begin()+n/2);
    v2.insert(v2.end(),v.begin()+n/2,v.end());
    int a=0,b=0,c=0,d=0;
    for(int i=0;i<v1.size();i++){
        if(v1[i].b==0){
            a++;
        }
        else{
            b++;
        }
    }

    for(int i=0;i<v2.size();i++){
        if(v2[i].b==0){
            c++;
        }
        else{
            d++;
        }
    }
    cout<<c<<" "<<d<<endl;
    cout<<a<<" "<<b<<endl;


    return 0;
}
