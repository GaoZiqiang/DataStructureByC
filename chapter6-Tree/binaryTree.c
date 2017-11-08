/*创建并遍历二叉数*/
#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW 0
#define OK 1

typedef int Status;
typedef char ElemType;
typedef struct BiTree
{
    ElemType data;
    struct BiTree *Lchild;
    struct BiTree *Rchild;
}BiTree,*Binary_Tree;
//创建一个二叉树

Binary_Tree  CreateBiTree(Binary_Tree T)
{
    char ch;
    T=(Binary_Tree)malloc(sizeof(BiTree));
    if(!T)
        exit(OVERFLOW);
    scanf("%c",&ch);
    if(ch=='0')
        T=NULL;
    else
    {
        T->data=ch;
        T->Lchild=CreateBiTree(T->Lchild);
        T->Rchild=CreateBiTree(T->Rchild);
   }
   return T;
}




//先遍历二叉树
Status PreShowBiTree(Binary_Tree T)
{
    if(T!=NULL)
    {
       printf("%c  ",T->data);
       PreShowBiTree(T->Lchild);
       PreShowBiTree(T->Rchild);
    }
    return OK;
}

//中遍历二叉树
Status MidShowBiTree(Binary_Tree T)
{
    if(T!=NULL)
    {
       MidShowBiTree(T->Lchild);
       printf("%c  ",T->data);
       MidShowBiTree(T->Rchild);
    }
    return OK;
}

//后遍历二叉树
Status BehShowBiTree(Binary_Tree T)
{
    if(T!=NULL)
    {
       BehShowBiTree(T->Lchild);
       BehShowBiTree(T->Rchild);
       printf("%c  ",T->data);
    }
    return OK;
}

int main()
{
    BiTree *T;
    printf("请创建一个二叉树，符号‘0’为叶子节点终止符:\n");
    T=CreateBiTree(T);
    printf("先序遍历: ");
    PreShowBiTree(T);
    printf("\n");
    printf("中序遍历:  \n");
    MidShowBiTree(T);
    printf("\n");
    printf("后序遍历: \n");
    BehShowBiTree(T);
    printf("\n");
}
