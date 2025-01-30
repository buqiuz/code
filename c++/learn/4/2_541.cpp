#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=2*k){
            if(i+k>s.size()) {
                reverse(s.begin()+i,s.end());
                break;
            }
            reverse(s.begin()+i,s.begin()+i+k);
        }
        return s;
    }
};