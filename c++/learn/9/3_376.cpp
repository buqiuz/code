#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<1) return 1;

        int flag = nums[1]-nums[0];
        int ret = (flag==0)?1:2;

        for(int i=2;i<nums.size();i++){
            int diff=nums[i]-nums[i-1];
            if(flag==0){
                if(diff==0) continue;
                else{
                    flag=diff;
                    ret++;
                }
            }
            if(flag>0){
                if(diff>=0) continue;
                else {
                    flag=diff;
                    ret++;
                }
            }
            if(flag<0){
                if(diff<=0) continue;
                else {
                    flag= diff;
                    ret++;
                }
            }
        }
        return ret;
    }
};

//精简版
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return 1;
        
        int flag = nums[1]-nums[0];
        int ret = (flag==0)?1:2;

        for(int i=2;i<nums.size();i++){
            int diff=nums[i]-nums[i-1];
            if((diff<0&&flag>0)||(diff>0&&flag<0)||(diff!=0&&flag==0)){
                flag=diff;
                ret++;
            }
            else continue;
        }
        return ret;
    }
};

//再简化
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        
        int up = 1;   // 当前上升摆动序列长度
        int down = 1; // 当前下降摆动序列长度
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                up = down + 1;
            } else if (nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }
        
        return max(up, down);
    }
};

int main(){
    vector<int> nums = {1,10};
    Solution s;
    cout<<s.wiggleMaxLength(nums)<<endl;
    return 0;
}