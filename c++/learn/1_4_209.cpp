#include<bits/stdc++.h>
using namespace std;

//初始版本  理解为只有等于target的时候才会记录
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow =0;
        int total =0;
        vector<pair<int, int>> ret;
        for(int fast=0; fast<nums.size(); fast++) {
            total += nums[fast];

            if(total==target){
                ret.emplace_back(slow, fast);
            }

            while(total>target){
                total -= nums[slow++];
                if(total==target){
                    ret.emplace_back(slow, fast);
                }
            }
        }
        sort(ret.begin(), ret.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second - a.first < b.second - b.first;
        });
        return ret.empty() ? 0 : ret[0].second - ret[0].first + 1;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow =0;
        int total =0;
        int ret=INT32_MAX;
        for(int fast=0; fast<nums.size(); fast++) {
            total += nums[fast];
            while(total>=target){
                ret=(fast-slow+1)<ret?fast-slow+1:ret;
                total -= nums[slow++];
            }
        }
        return ret==INT32_MAX?0:ret;
    }
};