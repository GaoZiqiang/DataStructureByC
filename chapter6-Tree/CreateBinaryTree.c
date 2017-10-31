/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 创建二叉树
 * 先序遍历二叉树
 * 中序遍历二叉树
 * 后序遍历二叉树
 */


#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW 0
#define OK 1

typedef int Status;
typedef char ElemType;
typedef struct BinaryTreeNode
{
    ElemType data;
    struct BinaryTreeNode *Lchild;
    struct BinaryTreeNode *Rchild;
}BinaryTreeNode,*BinaryTree;
//创建一个二叉树

BinaryTree  createBinaryTree(BinaryTree T)
{
    char ch;
    T=(BinaryTree)malloc(sizeof(BinaryTreeNode));
    if(!T)
        exit(OVERFLOW);
    scanf("%c",&ch);
    if(ch=='0')
        T=NULL;
    else
    {
        T->data=ch;
        T->Lchild=createBinaryTree(T->Lchild);
        T->Rchild=createBinaryTree(T->Rchild);
   }
   return T;
}




//先遍历二叉树
Status preOrderTraverse(BinaryTree T)
{
    if(T!=NULL)
    {
       printf("%c  ",T->data);
       preOrderTraverse(T->Lchild);
       preOrderTraverse(T->Rchild);
    }
    return OK;
}

//中遍历二叉树
Status midOrderTraverse(BinaryTree T)
{
    if(T!=NULL)
    {
       midOrderTraverse(T->Lchild);
       printf("%c  ",T->data);
       midOrderTraverse(T->Rchild);
    }
    return OK;
}

//后遍历二叉树
Status postOrderTraverse(BinaryTree T)
{
    if(T!=NULL)
    {
       postOrderTraverse(T->Lchild);
       postOrderTraverse(T->Rchild);
       printf("%c  ",T->data);
    }
    return OK;
}

int main()
{
    BinaryTreeNode *T;
    printf("请创建一个二叉树，符号‘0’为叶子节点终止符:\n");
    T=createBinaryTree(T);
    printf("先序遍历: ");
    preOrderTraverse(T);
    printf("\n");
    printf("中序遍历:  \n");
    midOrderTraverse(T);
    printf("\n");
    printf("后序遍历: \n");
    postOrderTraverse(T);
    printf("\n");
}