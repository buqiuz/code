#include<bits/stdc++.h>
using namespace std;

//初版
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret ;
        int n=nums.size()-1;

        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-1;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                
                int left=j+1;
                int right=n;
                while(left<right){
                    long sum =(long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target) {
                        ret.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left<right && nums[left]==nums[left-1]) left++;
                        while(left<right && nums[right]==nums[right+1]) right--;
                    }
                    else if(sum<target) left++;
                    else right--;
                }
            }
        }
        return ret;
    }
};

//版本一，剪枝后
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = nums.size();
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 跳过重复的 i
            // 剪枝：当前最小四数和大于 target，直接退出
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // 剪枝：当前最大四数和小于 target，当前 i 无法满足要求，跳过
            if ((long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // 跳过重复的 j
                // 剪枝：当前最小四数和大于 target，直接退出
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                // 剪枝：当前最大四数和小于 target，当前 j 无法满足要求，跳过
                if ((long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++, right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;  // 跳过重复值
                        while (left < right && nums[right] == nums[right + 1]) right--; // 跳过重复值
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ret;
    }
};
