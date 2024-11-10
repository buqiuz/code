#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    int a,b;
    string name;
    char c;
public:
    virtual void show (){
        cout<<a<<" "<<b<<" "<<name<<" "<<c<<endl;
    };
    Person(int a,int b,string name,char c):a(a),b(b),name(name),c(c){}
};

class Student:public Person
{
public:
    int score;
public:
    void show() override {
        cout<<a<<" "<<b<<" "<<name<<" "<<c<<" "<<score<<endl;
    }
    Student(int a,int b,string name,char c,int score):Person(a,b,name,c),score(score){}
};

int main (){

    // auto createVector = [](int n)->vector<int>{
    //     vector<int> v(n);
    //     for(int i=0;i<n;i++){
    //         cin>>v[i];
    //     }
    //     return v;
    // };

    // vector<int> v =createVector(5);
    // for_each(v.begin(),v.end(),[](auto x){cout<<x<<" ";});

    // Student s(1,2,"abc",'d',100);
    // Person& p =s;
    // p.show();
    // // cout<<p.a<<" "<<p.b<<" "<<p.name<<" "<<p.c<<endl;

    // regex r(R"(1000|\d{0,3})");
    // string s;
    // cin>>s;
    // if(regex_match(s,r)){
    //     cout<<"Matched"<<endl;
    // }
    // else{
    //     cout<<"Not Matched"<<endl;
    // }

    int s=10;
    while(s) 
        s++;

    cout<<" sfdfds";
    return 0; 
}
