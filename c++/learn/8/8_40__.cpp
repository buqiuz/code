#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//版本一
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    void backTracing(vector<int>& candidates,int target,int startIndex,vector<bool>& used){
        if(target==0){
            ret.push_back(path);
            return ;
        }
        if(target<0) return ;

        for(int i= startIndex;i<candidates.size()&&target-candidates[i]>=0;i++){  //剪枝,如果target-candidates[i]<0,则后面的数都不用看了
            if(i>startIndex&&candidates[i]==candidates[i-1]&&used[i-1]==false) continue;  //同一递归层跳过重复  这里的used其实可以不用,
            path.push_back(candidates[i]);
            used[i]=true;
            backTracing(candidates,target-candidates[i],i+1,used);  //i为1则表示下一递归可以重复使用自身，i+1则不可以 同一分支跳过重复 
            used[i]=false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());  //排序
        vector<bool> used(candidates.size(),false);
        backTracing(candidates,target,0,used);
        return ret;
    }
};

//精简版
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
            if(i>startIndex&&candidates[i]==candidates[i-1]) continue;
            path.push_back(candidates[i]);
            backTracing(candidates,target-candidates[i],i);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());  //排序
        backTracing(candidates,target,0);
        return ret;
    }
};