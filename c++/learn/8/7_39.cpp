#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    void backTracing(vector<int>& candidates,int target,int startIndex){
        if(target==0){
            ret.push_back(path);
            return ;
        }
        if(target<0) return ;

        for(int i= startIndex;i<candidates.size();i++){
            path.push_back(candidates[i]);
            backTracing(candidates,target-candidates[i],i);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracing(candidates,target,0);
        return ret;
    }
};

//剪枝
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    void backTracing(vector<int>& candidates,int target,int startIndex){
        if(target==0){
            ret.push_back(path);
            return ;
        }
        if(target<0) return ;

        for(int i= startIndex;i<candidates.size()&&target-candidates[i]>=0;i++){  //剪枝,如果target-candidates[i]<0,则后面的数都不用看了
            path.push_back(candidates[i]);
            backTracing(candidates,target-candidates[i],i);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());  //排序
        backTracing(candidates,target,0);
        return ret;
    }
};