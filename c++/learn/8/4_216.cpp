#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    void combination(int k,int n,int startIndex){
        if(path.size()==k&&n==0){
            ret.push_back(path);
            return ;
        }

        for(int i=startIndex;i<=9;i++){
            path.push_back(i);
            combination(k,n-i,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        combination(k,n,1);
        return ret;
    }
};