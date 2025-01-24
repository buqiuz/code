#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct oasis
{
    long long x,y,w,h;
};
long long min (long long a,long long b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
long long sq(vector<oasis> &v,long long x){
    long long sum=0;
    for(long long i=0;i<v.size();i++){
        if(v[i].x<x){
            sum+=v[i].h*(min(v[i].w+v[i].x,x)-v[i].x);
        }
    }
    return sum;
}
long long binarySearch (vector<oasis> &v,long long total){
    long long low=v[0].x,high=v[v.size()-1].x+v[v.size()-1].w;
    long long mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(sq(v,mid)==total*1.0/2){
            // cout<<mid<<endl;
            return mid;
        }
        if(sq(v,mid)<total*1.0/2){
            low=mid+1;
                       
        }
        if (sq(v,mid)>total*1.0/2) 
        {
            high=mid-1;
            
        }
        
    }
    // cout<<mid<<endl;
    return mid;
}


bool cmp(oasis& a,oasis& b){
    if(a.x<b.x){
        return 1;
    }
    return 0;
}

int main(){
    long long n;
    while (cin>>n)
    {
    vector<oasis> v(n);
    long long  total=0;
    for(long long i=0;i<n;i++){
        cin>>v[i].x>>v[i].y>>v[i].w>>v[i].h;
        total+=v[i].w*v[i].h;
    }
    sort(v.begin(),v.end(),cmp);

    long long x=binarySearch(v,total);

    if(sq(v,x-1)>=total*1.0/2&&sq(v,x-2)<total*1.0/2){
        cout<<x-1;
    }
    if(sq(v,x-1)<total*1.0/2&&sq(v,x)>=total*1.0/2){
        cout<<x;
    }
    if(sq(v,x)<total*1.0/2&&sq(v,x+1)>=total*1.0/2){
        cout<<x+1;
    }
    }
    
    
    return 0;
}