#include<bits/stdc++.h>
using namespace std;
int q;
struct treap{//封装 Treap
    struct node{
        long long x,y,l,r,size,cnt;
    };
    node map[1000001];
    long long top,root;
    void reset(){
        top=0;
        root=0;
    }
    void update(long long x){
        map[x].size=map[map[x].l].size+map[map[x].r].size+map[x].cnt;
    }
    void rotr(long long &x){
        long long l=map[x].l;
        map[x].l=map[l].r;
        map[l].r=x;
        map[l].size=map[x].size;
        update(x);
        x=l;
    }
    void rotl(long long &x){
        long long r=map[x].r;
        map[x].r=map[r].l;
        map[r].l=x;
        map[r].size=map[x].size;
        update(x);
        x=r;
    }
    void add(long long &x,long long data){
        if (!x){
            x=++top;
            map[x].x=data;
            map[x].y=rand()%19260817;
            map[x].cnt=1;
            map[x].size=1;
            map[x].l=0;
            map[x].r=0;
            return;
        }
        map[x].size++;
        if (map[x].x==data){
            map[x].cnt++;
        }else if (data<map[x].x){
            add(map[x].l,data);
            if (map[x].y>map[map[x].l].y){
                rotr(x);
            }
        }else{
            add(map[x].r,data);
            if (map[x].y>map[map[x].r].y){
                rotl(x);
            }
        }
    }
    void delet(long long &x,long long data){
        if (map[x].x==data){
            if (map[x].cnt>1){
                map[x].cnt--;
                map[x].size--;
                return;
            }
            if (!map[x].l||!map[x].r){
                x=map[x].l+map[x].r;
                return;
            }
            if (map[map[x].l].y<map[map[x].r].y){
                rotr(x);
                delet(x,data);
            }else{
                rotl(x);
                delet(x,data);
            }
            return;
        }
        map[x].size--;
        if (data<map[x].x){
            delet(map[x].l,data);
        }else{
            delet(map[x].r,data);
        }
    }
    long long pre(long long data){
        long long now=root,res=-2147483647;
        while (now){
            if (map[now].x<data){
                res=map[now].x;
                now=map[now].r;
            }else{
                now=map[now].l;
            }
        }
        return res;
    }
    long long nxt(long long data){
        long long now=root,res=2147483647;
        while (now){
            if (map[now].x>data){
                res=map[now].x;
                now=map[now].l;
            }else{
                now=map[now].r;
            }
        }
        return res;
    }
    long long querykth(long long k){
        long long now=root;
        while (now){
            if (map[map[now].l].size<k&&map[map[now].l].size+map[now].cnt>=k){
                return map[now].x;
            }
            if (map[map[now].l].size>=k){
                now=map[now].l;
            }else{
                k-=map[map[now].l].size+map[now].cnt;
                now=map[now].r;
            }
        }
        return 0;
    }
    long long queryrank(long long data){
        long long now=root,res=0;
        while (now){
            if (data==map[now].x){
                return res+map[map[now].l].size+1;
            }
            if (data<map[now].x){
                now=map[now].l;
            }else{
                res+=map[map[now].l].size+map[now].cnt;
                now=map[now].r;
            }
        }
        return res;
    }
};
long long n,ans=0;
treap a,b;
long long A=0,B=0;
int main(){
    srand(time(0));
    a.reset();
    b.reset();
    cin>>n;
    for (int i=1;i<=n;i++){
        long long x,y;
        cin>>x>>y;
        if (x==0){
            if (B>0){
                long long tar1=b.pre(y);
                long long tar2=b.nxt(y);
                if (y-tar1>tar2-y){
                    ans+=tar2-y;
                    b.delet(b.root,tar2);
                }else{
                    ans+=y-tar1;
                    b.delet(b.root,tar1);
                }
                B--;
            }else{
                A++;
                a.add(a.root,y);
            }
        }else{
            if (A>0){
                long long tar1=a.pre(y);
                long long tar2=a.nxt(y);
                if (y-tar1>tar2-y){
                    ans+=tar2-y;
                    a.delet(a.root,tar2);
                }else{
                    ans+=y-tar1;
                    a.delet(a.root,tar1);
                }
                A--;
            }else{
                B++;
                b.add(b.root,y);
            }
        }
        ans%=1000000;
    }
    cout<<ans%1000000;
}