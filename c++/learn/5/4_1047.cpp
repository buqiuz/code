#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(auto x:s){
            if(!stk.empty()&&stk.top()==x) stk.pop();
            else stk.push(x);
        }
        string ret;
        while(!stk.empty()){
            ret+=stk.top();
            stk.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

//版本一
class Solution {
public:
    string removeDuplicates(string S) {
        string result;
        for(char s : S) {
            if(result.empty() || result.back() != s) result.push_back(s);
            else result.pop_back();
        }
        return result;
    }
};