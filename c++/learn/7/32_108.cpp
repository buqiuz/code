#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
public:
    TreeNode* ArrayToBST(vector<int>& nums,int left,int right){
        if(right<left) return nullptr;
        int mid = left + (right-left)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = ArrayToBST(nums,left,mid-1);
        node->right = ArrayToBST(nums,mid+1,right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ArrayToBST(nums,0,nums.size()-1);
    }
};