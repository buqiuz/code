#include <bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int,int> m;
        for(auto x: nums1){
            for(auto y: nums2){
                m[x+y]++;
            }
        }

        int count=0;

        for(auto x:nums3){
            for(auto y:nums4){
                auto it = m.find(0-(x+y));
                if(it!=m.end()) count+=it->second;
            }
        }
        return count;
    }
};