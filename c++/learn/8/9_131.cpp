#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
//初版
class Solution {
private:
    vector<vector<string>> ret;
    vector<string> path;
    void backTracing(string& s,int startIndex){
        if(startIndex>=s.size()){
            ret.push_back(path);
            return ;
        }
        auto isPalindrome = [&](int start,int end)->bool{
            for(int i=start,j=end;i<j;i++,j--){
                if(s[i]!=s[j]) return false;
            }
            return true;
        };
        
        for(int i = startIndex;i<s.size();i++){
            if(isPalindrome(startIndex,i)) path.push_back(s.substr(startIndex,i-startIndex+1));
            else continue;

            backTracing(s,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backTracing(s,0);
        return ret;
    }
};