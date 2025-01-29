#include <bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end()), ret;
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(ret, ret.begin()));
        return vector<int>(ret.begin(), ret.end());
    }
};


//版本一
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end()), ret;
        for(auto x:set1){
            if(set2.find(x)!=set2.end()){
                ret.insert(x);
            }
        }
        return vector<int>(ret.begin(), ret.end());
    }
};
