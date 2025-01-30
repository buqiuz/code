#include <bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,vector<pair<int,int>>> m;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                m[nums[i]+nums[j]].push_back({i,j});
            }
        }
        set<vector<int>> s;

        for(int i=0;i<nums.size();i++){
            if(m.find(-nums[i])!=m.end()){
                for(auto x:m[-nums[i]]){
                    if(i!=x.first&&i!=x.second){
                        vector<int> v {nums[x.first],nums[x.second],nums[i]}; 
                        sort(v.begin(),v.end());
                        s.insert(v);
                    }
                }
            }
        }
        return vector<vector<int>>(s.begin(),s.end());
    }
};

//版本一
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;i++){
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;   
            unordered_set<int> m;
            for(int j=i+1;j<nums.size();j++){
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                    continue;
                int target = -(nums[j]+nums[i]);
                auto it=m.find(target);
                if(it!=m.end()) {
                    ret.push_back({nums[i],nums[j],target});
                    m.erase(it);
                }
                else m.insert(nums[j]);
            }
        }
        return ret;
    }
};

//版本二
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ret;
        for(int i=0;i<nums.size()-2;i++){

            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;

            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0) right--;
                else if(nums[i]+nums[left]+nums[right]<0) left++;
                else {
                    ret.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }
            }
        }
        return ret;
    }
};