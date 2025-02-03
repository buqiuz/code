#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版 其中root1&&root1!=root2?是因为root1可能已经被修改过了，不是原来的root1了
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1&&!root2) return nullptr;
        if(root1&&root2) root1->val+=root2->val;
        if(!root1&&root2) root1=root2;
        root1->left= mergeTrees(root1&&root1!=root2?root1->left:nullptr,root2? root2->left:nullptr);
        root1->right= mergeTrees(root1&&root1!=root2?root1->right:nullptr,root2? root2->right:nullptr);
        return root1;
    }
};


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2){
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left,root2->left);
            root2->right = mergeTrees(root1->right,root2->right);
        }
        return root1 ? root1 : root2;
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 && root2) {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        }
        return root1 ? root1 : root2;
    }
};