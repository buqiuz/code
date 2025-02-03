#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
public:
    void inorder(TreeNode* node){
        if(!node) return;
        inorder(node->left);
        ret.push_back(node->val);
        inorder(node->right);
    }
    
    bool isValidBST(TreeNode* root) {
        //错误版本，因为左子树的所有节点都要小于根节点，右子树的所有节点都要大于根节点，并不是单纯的左子树小于根节点，右子树大于根节点

        // if(!root) return true;  
        // if(root->left&&root->left->val>=root->val) return false;
        // if(root->right&&root->right->val<=root->val) return false;
        // return isValidBST(root->left)&&isValidBST(root->right);

        inorder(root);
        for(int i=0;i<ret.size()-1;i++){
            if(ret[i]>=ret[i+1]) return false;
        }
        return true;
    }
private:
    vector<int> ret;
};

//版本一  无需额外的空间开销
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool left=isValidBST(root->left);

        if(pre&&pre->val>=root->val) return false;
        pre=root;

        bool right=isValidBST(root->right);
        return left&&right;
    }
private:
    TreeNode* pre=nullptr;
};