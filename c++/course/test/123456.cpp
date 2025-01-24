#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> inorder_map;
        
        for (int i = 0; i < n; ++i) {
            inorder_map[inorder[i]] = i;
        }
        
        return buildTreeHelper(postorder, 0, n - 1, inorder, 0, n - 1, inorder_map);
    }
    
    TreeNode* buildTreeHelper(vector<int>& postorder, int post_start, int post_end,
                              vector<int>& inorder, int in_start, int in_end,
                              unordered_map<int, int>& inorder_map) {
        if (post_start > post_end || in_start > in_end) {
            return NULL;
        }
        
        int root_val = postorder[post_end];
        TreeNode* root = new TreeNode(root_val);
        
        int root_index_inorder = inorder_map[root_val];
        int num_left = root_index_inorder - in_start;
        
        root->left = buildTreeHelper(postorder, post_start, post_start + num_left - 1,
                                     inorder, in_start, root_index_inorder - 1,
                                     inorder_map);
        
        root->right = buildTreeHelper(postorder, post_start + num_left, post_end - 1,
                                      inorder, root_index_inorder + 1, in_end,
                                      inorder_map);
        
        return root;
    }
    
    void preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};

int main() {
    int n;
    while (cin >> n) {
        vector<int> postorder(n);
        vector<int> inorder(n);
        for (int i = 0; i < n; ++i) {
            cin >> postorder[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> inorder[i];
        }

        Solution solution;
        TreeNode* root = solution.buildTree(inorder, postorder);

        int depth = solution.maxDepth(root);
        cout << depth << " ";

        solution.preorderTraversal(root);
        cout << endl;
    }

    return 0;
}




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class solution {
public:
    unordered_map<int,int> idx_map;

    TreeNode* helper(vector<int>& preorder,int pre_left,int pre_right,vector<int>& inorder,int in_left,int in_right){
        if(pre_left>pre_right||in_left>in_right)
            return nullptr;

        int val=preorder[pre_left];
        int idx=idx_map[val];
        int left_size=idx-in_left;
        TreeNode* root=new TreeNode(val);
        root->left=helper(preorder,pre_left+1,pre_left+left_size,inorder,in_left,in_left+left_size-1);
        root->right=helper(preorder,pre_left+left_size+1,pre_right,inorder,in_left+left_size+1,in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<preorder.size();i++){
            idx_map[inorder[i]]=i;
        }
        return helper(preorder,0,n-1,inorder,0,n-1);
    }
};
