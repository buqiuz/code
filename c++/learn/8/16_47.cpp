#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> ret;
    vector<int> path;
    void backTracing(vector<int>& nums,vector<bool>& used){
        if(path.size()==nums.size()) {
            ret.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++){                                            //神奇,!used[i-1]和used[i-1]都能通过,但是!used[i-1]是树层去重,分支更少
            if(used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) continue; //同一树枝上,不能重复使用某个下标的元素,
                                                                                   // 同一层上,不能重复使用某个值的元素(假如前一个元素使用过,则当前层可以使用,因为在不同层)
            path.push_back(nums[i]);
            used[i]=true;
            backTracing(nums,used);
            used[i]=false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backTracing(nums,used);
        return ret;
    }
};