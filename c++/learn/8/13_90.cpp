#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    void backTracing(vector<int>& nums,int startIndex){
        ret.push_back(path);
        if(startIndex>nums.size()) return ;

        for(int i = startIndex;i<nums.size();i++){
            if(i>startIndex&&nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            backTracing(nums,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());  //排序
        backTracing(nums,0);
        return ret;
    }
};