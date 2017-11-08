#include <stdio.h>
#include <malloc.h>

typedef struct BinaryTreeNode{
    char value;
    struct  BinaryTreeNode *left;
    struct BinaryTreeNode *right;
}BinaryTreeNode,*BinaryTree;
void CreateBinaryTree(BinaryTreeNode **T)
{

    char data;
    scanf("%d",&data);
    if(data=='#')
        *T=NULL;
    else 
    {
         *T=(BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
         (*T)->value=data;

         CreateBinaryTree(&((*T)->left));
         CreateBinaryTree(&((*T)->right));
    }
}

int main() {
   BinaryTreeNode *T;
   CreateBinaryTree(T);

   return 0;
}
