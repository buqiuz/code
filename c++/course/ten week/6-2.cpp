#include<stdio.h>
#include<malloc.h>
#define len sizeof(struct BiTNode )

typedef struct BiTNode
{
    char data;  //数据域
    struct BiTNode *lchild;  //左孩子指针
    struct BiTNode *rchild;  //右孩子指针
}BiTNode,*BiTree;

 void creat(BiTree &Tree);//构建二叉树

int Depth(BiTree Tree);//求深度

int main()
{
    BiTree Tree;
    creat(Tree);//创建二叉树
    printf("%d\n",Depth(Tree));
    return 0;
}
/* 请在这里填写答案 */
#include <iostream>
void creat(BiTree &Tree){
    char a;
    std::cin>>a;
    
    if(a=='#'){
        Tree=NULL;
    }else{
        Tree=new BiTNode;
        Tree->data=a;
        creat(Tree->lchild);
        creat(Tree->rchild);
    }
}
int max(int a,int b    ){
    if(a>b)return a;
    return b;
}
int Depth(BiTree Tree) {
    if (Tree == nullptr) {
        return 0; // 空树的深度为0
    } else {
        int leftDepth = Depth(Tree->lchild);
        int rightDepth = Depth(Tree->rchild);
        return 1 + max(leftDepth, rightDepth);
    }
}


// 输入样例:ABC##DE#G##F###