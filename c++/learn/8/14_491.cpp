#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
private:
    vector<int> path;
    set<vector<int>> s;
    void backTracing(vector<int>& nums,int startIndex){
        if(path.size()>1){
            s.insert(path);
        }

        for(int i=startIndex;i<nums.size();i++){
            if(path.empty()||path.back()<=nums[i]){
                path.push_back(nums[i]);
                backTracing(nums,i+1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTracing(nums,0);
        vector<vector<int>> ret(s.begin(),s.end());
        return ret;
    }
};

//版本一
class Solution {
private:
    vector<int> path;
    vector<vector<int>> ret;
    void backTracing(vector<int>& nums,int startIndex){
        if(path.size()>1){
            ret.push_back(path);
        }

        unordered_set<int> uesdSet;
        for(int i=startIndex;i<nums.size();i++){
            if(uesdSet.find(nums[i])!=uesdSet.end()) continue;

            if(path.empty()||path.back()<=nums[i]){
                path.push_back(nums[i]);
                uesdSet.insert(nums[i]);
                backTracing(nums,i+1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTracing(nums,0);
        return ret;
    }
};