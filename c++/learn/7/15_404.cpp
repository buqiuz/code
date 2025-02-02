#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        if(root->left&&!root->left->left&&!root->left->right) sum+=root->left->val;  //这里不能直接返回,不然的话会漏掉右子树
        return sum+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};