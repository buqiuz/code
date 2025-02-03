#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版，没考虑这是二叉搜索树
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val == val) return root;
        TreeNode* left = searchBST(root->left,val);
        TreeNode* right = searchBST(root->right,val);
        return left?left:right;
    }
};

//版本一
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val == val) return root;
        if(root->val>val) return searchBST(root->left,val);
        if(root->val<val) return searchBST(root->right,val);
        return nullptr;
    }
};