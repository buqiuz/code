#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int min = INT32_MAX;
        inorder(root,min);
        return min;
    }
private:
    TreeNode* pre=nullptr;
    void inorder(TreeNode* root,int& min) {
        if(!root) return ;
        inorder(root->left,min);

        if(pre) min= root->val-pre->val<min?root->val-pre->val:min;
        pre = root;
        
        inorder(root->right,min);
    }
};