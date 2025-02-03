#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    // TreeNode* level(TreeNode* root, TreeNode* p, TreeNode* q){
    //     queue<TreeNode*> que;
    //     if(root) que.push(root);
    //     TreeNode* ret = nullptr;
    //     TreeNode* old = nullptr;
    //     while(!que.empty()){
    //         int size = que.size();
    //         for(int i=0;i<size;i++){
    //             TreeNode* node = que.front();
    //             que.pop();
    //             if((node->val<=p->val&&node->val>=q->val)||
    //                 (node->val>=p->val&&node->val<=q->val)||
    //                 (node->val>=p->val&&node->val>=q->val)||
    //                 (node->val<=p->val&&node->val<=q->val)){
    //                 old=ret;
    //                 ret=node;
    //                 cout<<ret->val<<endl;
    //             }
    //             if(node->left) que.push(node->left);
    //             if(node->right) que.push(node->right);
    //         }
    //         if(ret==old) break;
    //     }
    //     return ret;
    // }

    //后序遍历回溯法找到就返回然后层层返回

    //在一层递归中,如果p和q的值都小于当前节点,则从左子树中寻找(直接假设会找到)
    //            如果都大于当前节点,则从右子树中寻找(直接假设会找到)
    //            如果一个大于一个小于,则当前节点就是最近公共祖先(递归终止条件) *****最重要的就是确定递归终止条件
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(!root) return nullptr;        //不需要这个判断,因为会提前返回root,不会碰到空节点,也就是说不会遍历完这整棵树
        if(root->val>p->val&&root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        if(root->val<p->val&&root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
    
};