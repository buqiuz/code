#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
private:
    vector<string> ret;
    string path;
    unordered_map<char,string> m {
        {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };
    void backTracing(string digits){
        if(digits.empty()) return ; //空的话返回空字符串

        if(path.size()==digits.size()){
            ret.push_back(path);
            return ;
        }

        char ch = digits[path.size()];

        for(int i=0;i<m[ch].size();i++){
            path.push_back(m[ch][i]);
            backTracing(digits);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        backTracing(digits);
        return ret;
    }
};