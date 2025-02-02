#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
public:
    TreeNode* build (vector<int>& nums,int start,int end){
        if(end<start) return nullptr;
        int index,max=INT32_MIN;
        for(int i=start;i<=end;i++){
            if(max<nums[i]){
                max=nums[i];
                index=i;
            }
        }
        TreeNode* node = new TreeNode(max);

        node->left = build(nums,start,index-1);
        node->right = build(nums,index+1,end);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};