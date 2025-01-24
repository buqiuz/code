#include<bits/stdc++.h>
using namespace std;

//初版  一坨，不用研究
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j= nums.size()-1;
        int count = 0;
        if(i==j){
            if(nums[0]==val){
                return 0;
            }
        }
        while(i<j){
            while(nums[i]!=val) i++;
            while(nums[j]==val) {
                j--;
                count++;
            }
            if(i<j){
                swap(nums[i],nums[j]);
                i++;
                j--;
                count++;
            }
        }
        return nums.size()-count;
    }
};

// 版本一
class Solution {
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};

// 版本二
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0;
        for (int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=val){
                nums[slow++]=nums[fast];
            }
        }
        return slow;
    }
};
