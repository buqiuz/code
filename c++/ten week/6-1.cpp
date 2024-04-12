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
int countleaf(BiTree Tree);//求叶子结点个数
 
int main()
{
    BiTree Tree;
    creat(Tree);//创建二叉树
    printf("%d\n",countleaf(Tree)); //输入叶子节点个数
    return 0;
}

/* 请在这里填写答案 */
void creat(BiTree &Tree)
{
    char data;
    scanf("%c", &data);

    if (data == '#') // 输入'#'表示空节点
    {
        Tree = NULL;
    }
    else
    {
        Tree = (BiTree)malloc(sizeof(BiTNode));
        Tree->data = data;
        creat(Tree->lchild); // 递归创建左子树
        creat(Tree->rchild); // 递归创建右子树
    }
}

int countleaf(BiTree Tree)
{
    if (Tree == NULL)
    {
        return 0; // 空树没有叶子节点
    }
    else if (Tree->lchild == NULL && Tree->rchild == NULL)
    {
        return 1; // 只有一个节点的树是叶子节点
    }
    else
    {
        return countleaf(Tree->lchild) + countleaf(Tree->rchild); // 递归计算左右子树的叶子节点数量
    }
}


// 输入样例:ABC##DE#G##F###