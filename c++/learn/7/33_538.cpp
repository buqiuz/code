#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版 反着来,右中左也就是降序
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr ;
        convertBST(root->right);

        if(pre) root->val+=pre->val;
        pre = root;

        convertBST(root->left);
        return root;
    }
private:
    TreeNode* pre= nullptr;
};