#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T value): data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class bst {
private:
    TreeNode<T>* root;

    TreeNode<T>* insert(TreeNode<T>* node, T value) {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }

        if (node->data < value) {
            node->right = insert(node->right, value);
        } else if (node->data > value) {
            node->left = insert(node->left, value);
        }

        return node;
    }

    TreeNode<T>* search(TreeNode<T>* node, T value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (node->data < value) {
            return search(node->right, value);
        } else {
            return search(node->left, value);
        }
    }

public:
    bst() : root(nullptr) {}

    void insert(T value) {
        root = insert(root, value);
    }

    TreeNode<T>* search(T value) {
        return search(root, value);
    }
};

int main() {
    bst<int> tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(8);
    tree.insert(9);
    tree.insert(15);

    TreeNode<int>* result = tree.search(10);
    if (result == nullptr) {
        cout << "-1";
    } else {
        cout << result->data;
    }

    return 0;
}
