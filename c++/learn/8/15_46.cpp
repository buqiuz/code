#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    void backTracing(vector<int>& nums,vector<bool>& used){
        if(path.size()==nums.size()){
            ret.push_back(path);
            return ;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            path.push_back(nums[i]);
            used[i]=true;
            backTracing(nums,used);
            used[i]=false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backTracing(nums,used);
        return ret;
    }
};