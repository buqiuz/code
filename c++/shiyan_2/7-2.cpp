#include<stdio.h>
#include<malloc.h>
#define len sizeof(struct BiTNode )
#include <iostream>
using namespace std;

typedef struct BiTNode
{
    char data;  //数据域
    struct BiTNode *left;  //左孩子指针
    struct BiTNode *right;  //右孩子指针
}BiTNode,*BiTree;

void creat(BiTree &Tree);//构建二叉树
void creat(BiTree &Tree){
    char a;
    std::cin>>a;
    
    if(a=='#'){
        Tree=NULL;
    }else{
        Tree=new BiTNode;
        Tree->data=a;
        creat(Tree->left);
        creat(Tree->right);
    }
}
void mid_s(BiTree &Tree){
    if(Tree!=nullptr){
    
    mid_s(Tree->left);
    cout<<Tree->data;
    mid_s(Tree->right);
    }
}

int main()
{
    BiTree Tree;
    creat(Tree);//创建二叉树
    mid_s(Tree);
    return 0;
}



