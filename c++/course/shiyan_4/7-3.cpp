#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int flag=0;
int n; 

//二叉搜索树结点类型
template<typename T>
struct BSTNode
{
    T data;    //数据域
    BSTNode<T> *left, *right;    //左子女、右子女
    BSTNode() :left(NULL), right(NULL) {}    //构造函数
    //构造函数
    BSTNode(const T d, BSTNode<T>* L = NULL, BSTNode<T>* R = NULL) :data(d), left(L), right(R) {}
};

//二叉搜索树的定义
template <class T>
class BST
{
public:
    //普通构造函数
    BST() :root(NULL) {}
    //构造BST
    BST(T value) :root(NULL), RefValue(value)
    {
        T x;
        cin >> x;
        while (x != RefValue)
        {
            Insert(x, root);    //新建一个结点，调用Insert插入到树中
            cin >> x;
        }
    }
    //析构
    ~BST() { Destroy(root); }
    //插入
    bool Insert(T x) { return Insert(x, root); }
    //删除
    bool Remove(T x) { return Remove(x, root); }
    //搜索
    bool Search(T x) { return (Search(x, root) != NULL) ? true : false; }
    //中序遍历
    void InOrder() { InOrder(root); }
    void PreOrder() { PreOrder(root); }
    void lastOrder() { lastOrder(root); }
    void levelOrder() { levelOrder(root); }
    

protected:

    //以ptr为根的二叉搜索树中插入所含值为e1的结点
    bool Insert(const T& e1, BSTNode<T>* &ptr)    //第二个参数是指针的引用
    {
        if (ptr == NULL)
        {
            ptr = new BSTNode<T>(e1);    //构造新结点
            if (ptr == NULL)
            {
                cout << "Memory allocation failed!" << endl;
                exit(1);
            }
            return true;
        }
        else if (e1 < ptr->data)    //小于，插入左子树
        {
            Insert(e1, ptr->left);
        }
        else if (e1 > ptr->data)    //大于，插入右子树
        {
            Insert(e1, ptr->right);
        }
        else    //x已在树中，不插入
        {
            return false;
        }
    }

    //以ptr为根的二叉搜索树中删除含x的结点
    bool Remove(T x, BSTNode<T>* &ptr)
    {
        BSTNode<T>* temp;
        if (ptr != NULL) //ptr不为空进行操作
        {
            if (x < ptr->data)
            {
                Remove(x, ptr->left);
            }
            else if (x > ptr->data)
            {
                Remove(x, ptr->right);
            }
            //找到了要删除的结点
            //1.要删除的结点ptr同时有左右子树
            else if (ptr->left != NULL&&ptr->right != NULL)
            {
                temp = ptr->right;    //在右子树中搜索中序下的第一个结点
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                //用右子树中序下的第一个结点的值填充要删除的结点
                ptr->data = temp->data;
                //然后再新填充值ptr的右子树中删除temp的data值
                Remove(ptr->data, ptr->right);
            }
            else //不同时有左右子树
            {
                temp = ptr;        //temp记住要删除的ptr结点
                if (ptr->left == NULL) //只有右子树
                {
                    ptr = ptr->right;
                }
                else    //只有左子树
                {
                    ptr = ptr->left;
                }
                delete temp;    //删除结点
                temp = NULL;
                return true;
            }
        }
        else //ptr为空直接返回false
        {
            return false;
        }
    }

    //在ptr为根的二叉搜索树中搜索含x的结点。若找到，返回该结点地址，否则返回NULL
    BSTNode<T>* Search(T x, BSTNode<T>* ptr)
    {
        if (ptr == NULL)
        {
            return NULL;
        }
        else if (x < ptr->data)
        {
            return Search(x, ptr->left);
        }
        else if (x > ptr->data)
        {
            return Search(x, ptr->right);
        }
        else
        {
            return ptr;
        }
    }

    //中序遍历
    void InOrder(BSTNode<T>* root)
    {
        if (root != NULL)
        {
            InOrder(root->left);
            cout << root->data ;
            if(flag!=n-1){
            cout<<" ";
            flag++;
            }
            InOrder(root->right);
        }
    }
    void PreOrder(BSTNode<T>* root)
    {
        if (root != NULL)
        {
            cout << root->data ;
            if(flag!=n-1){
            cout<<" ";
            flag++;
            }
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }
    void lastOrder(BSTNode<T>* root)
    {
        if (root != NULL)
        {    
            lastOrder(root->left);
            lastOrder(root->right);
            cout << root->data ;
            if(flag!=n-1){
            cout<<" ";
            flag++;
            }
        }
    }
    void levelOrder(BSTNode<T>* root) {
    if (!root) return;
    std::queue<BSTNode<T>*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        std::cout << node->data ;
        if(flag!=n-1){
            cout<<" ";
            flag++;
            }
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

    //销毁以root为根的二叉树搜索树函数
    void Destroy(BSTNode<T>* &root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left != NULL)
        {
            Destroy(root->left);
        }
        if (root->right != NULL)
        {
            Destroy(root->right);
        }
        delete root;
        root = NULL;
    }
private:
    BSTNode<T>* root;    //根指针
    T RefValue;    //输入结束标识
};

int main(int argc, char* argv[])
{
    //g a e d f h j i l k #
    BST<int> tree;

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        tree.Insert(a);
    }
    tree.PreOrder();
    cout<<endl;
    flag=0;
    tree.InOrder();
    cout<<endl;
    flag=0;
    tree.lastOrder();
    cout<<endl;
    flag=0;
    tree.levelOrder();
    

    return 0;
}



