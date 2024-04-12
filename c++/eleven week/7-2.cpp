#include<iostream>
#include<vector>

using namespace std;
int b=0;
struct BitNode
{
    int data;
    int cs=0;
    BitNode *left=nullptr;
    BitNode *right=nullptr;
};
void pre(BitNode* tree){
    if(tree!=nullptr){
        tree->cs++;
        pre(tree->left);
        pre(tree->right);
    }
}
int pre_count(BitNode* tree){
    if(tree!=nullptr){
        if(tree->left==nullptr&&tree->right==nullptr){
            return b+=tree->cs*tree->data;
        }
        pre_count(tree->left);
        pre_count(tree->right);
    }
    return b;
}

int calculateWPL(BitNode* root, int depth = 0) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return depth * root->data;
    }

    return calculateWPL(root->left, depth + 1) + calculateWPL(root->right, depth + 1);
}

int main(){
    int n;
    cin>>n;
    vector<BitNode*> v(n);
    for(int i=0;i<n;i++)    {
        int a;
        cin>>a;
        v[i]=new BitNode;
        v[i]->data=a;
    }for(int i=1;i<n;i++){
        int min=0;
        for(int j=1;j<v.size();j++){
            if(v[j]->data<v[min]->data){
                min=j;
            }
        }
//        BitNode* temp=v[min];

        BitNode* tree=new BitNode;
        tree->left=v[min];
        v.erase(v.begin()+min);

        min=0;
        for(int j=1;j<v.size();j++){
            if(v[j]->data<v[min]->data){
                min=j;
            }
        }
        tree->right=v[min];
        v.erase(v.begin()+min);
        pre(tree);
        tree->cs--;
        tree->data=tree->left->data+tree->right->data;
        v.insert(v.begin(),tree);

    }
    BitNode* tree=v[0];
    cout<<pre_count(tree);

    return 0;
}








// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// struct BitNode
// {
//     int data;
//     int cs = 0;
//     BitNode* left = nullptr;
//     BitNode* right = nullptr;
// };

// // 比较函数，用于优先队列
// struct CompareNodes
// {
//     bool operator()(BitNode* a, BitNode* b)
//     {
//         return a->data > b->data;
//     }
// };

// // 构建哈夫曼树
// BitNode* buildHuffmanTree(vector<BitNode*>& nodes)
// {
//     priority_queue<BitNode*, vector<BitNode*>, CompareNodes> pq(nodes.begin(), nodes.end());

//     while (pq.size() > 1)
//     {
//         BitNode* left = pq.top();
//         pq.pop();

//         BitNode* right = pq.top();
//         pq.pop();

//         BitNode* newNode = new BitNode;
//         newNode->data = max(left->data, right->data); // 改为使用 max 而不是 +
//         newNode->left = left;
//         newNode->right = right;

//         pq.push(newNode);
//     }

//     return pq.top();
// }

// // 计算带权路径长度
// int calculateWPL(BitNode* root, int depth = 0)
// {
//     if (root == nullptr)
//     {
//         return 0;
//     }

//     if (root->left == nullptr && root->right == nullptr)
//     {
//         return depth * root->data;
//     }

//     return calculateWPL(root->left, depth + 1) + calculateWPL(root->right, depth + 1);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<BitNode*> v(n);
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         v[i] = new BitNode;
//         v[i]->data = a;
//     }

//     BitNode* tree = buildHuffmanTree(v);
//     int wpl = calculateWPL(tree);

//     cout << wpl;

//     return 0;
// }
