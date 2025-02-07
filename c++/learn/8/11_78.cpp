#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    void backTracing(vector<int>& nums,int startIndex){
        if(startIndex>nums.size()) return;

        for(int i=startIndex;i<nums.size();i++){
            path.push_back(nums[i]);
            ret.push_back(path);
            backTracing(nums,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backTracing(nums,0);
        ret.push_back({});
        return ret;
    }
};

//版本一 更简洁
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    void backTracing(vector<int>& nums,int startIndex){
        ret.push_back({});
        if(startIndex>nums.size()) return;

        for(int i=startIndex;i<nums.size();i++){
            path.push_back(nums[i]);
            backTracing(nums,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backTracing(nums,0);
        return ret;
    }
};