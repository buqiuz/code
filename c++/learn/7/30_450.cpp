

//初版  会遍历整棵树
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;   //因为有空树,所以要提前返回
        if(root->val==key){   //终止条件即找到了要删除的节点
            if(root->left) {
                TreeNode* temp = root->left;
                while(temp->right) temp=temp->right;
                temp->right = root->right;
                return root->left;
            }
            else return root->right;
        }
        root->left = deleteNode(root->left,key);
        root->right = deleteNode(root->right,key);
        return root;
    }
};

//改进版 优化遍历次数
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key){
            if(root->left) {
                TreeNode* temp = root->left;
                while(temp->right) temp=temp->right;
                temp->right = root->right;
                return root->left;
            }
            else return root->right;
        }
        if(root->val>key) root->left = deleteNode(root->left,key);
        if(root->val<key) root->right = deleteNode(root->right,key);
        return root;
    }
};