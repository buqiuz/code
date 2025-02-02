#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//初版
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};

//迭代