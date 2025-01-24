#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left =0,right = nums.size()-1,mid=0;
        
        if(right==0) return -1;

        while(left<right){
            mid = (left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                left = mid;
            }else {
                right = mid;
            }
        }
        return -1;
    }
};

int main (){
    Solution s;
    //nums = [-1,0,3,5,9,12], target = 9
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout<<s.search(nums,target)<<endl;
    return 0; 
}
