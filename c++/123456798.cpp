#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int removeElement(vector<int>& nums, int val) {
    int i=0;
    int j=nums.size()-1;
    while(i<=j){
        if(nums[i]==val) swap(nums[i],nums[j--]); 
        else i++;
    }
    return i;
}
};

int main (){
    vector<int> nums = {3,2,2,3};
    int val = 3;
    Solution s;
    cout<<s.removeElement(nums,val)<<endl;
    return 0;
}