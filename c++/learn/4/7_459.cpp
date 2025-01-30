#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str=s+s;
        str=str.substr(1,str.size()-2);
        if(str.find(s)!=std::string::npos) return true;
        return false;
    }
};