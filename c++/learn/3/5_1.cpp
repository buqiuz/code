#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            auto it=m.find(target-nums[i]);
            if(it!=m.end()) return vector<int> {it->second,i};
            m.insert(pair<int,int>(nums[i],i));
        }
        return vector<int> {};
    }
};