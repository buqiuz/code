#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//原版
class Solution {
public:
    bool has(TreeNode* node,int& targetSum,int sum){
        if(!node) return false;
        sum+=node->val;
        if(!node->left&&!node->right&&sum==targetSum) return true;
        return has(node->left,targetSum,sum)||has(node->right,targetSum,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return has(root,targetSum,0);
    }
};


//版本一
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(root->val==targetSum&&!root->left&&!root->right) return true;
        return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
    }
};