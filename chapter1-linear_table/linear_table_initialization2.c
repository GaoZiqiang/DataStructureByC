#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100 //初始分配量
#define LIST_INCREMENT 10  //分配增量
typedef int Status;

//线性表的动态分配顺序存储结构
typedef struct
{
int *Elem;          //存储空间的基址
int  Len;           //当前长度
int  ListSize;      //当前分配的存储容量
}SqList;

//构造一个空的线性表L
Status InitList(SqList *L)
{
//int i;
L->Elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
if(!L->Elem)
{
printf("初始化失败!");
exit(0);
}
L->Len = 0;
L->ListSize = LIST_INIT_SIZE;

return OK;
}
//-------获取某个元素---------
Status GetElem(SqList L,int i,int  *e)
{
if(L.Len == 0 || i < 1 || i > L.Len)
return ERROR;
//*e = L.Elem[i - 1];
*e = *(L.Elem + i - 1);
return OK;
}
//--------------插入某个元素-----------------
Status ListInsert(SqList *L,int i, int e)//第二个元素前插入元素e
{
int k;
if(L->Len == LIST_INIT_SIZE )
return ERROR;
if(i < 1 || i > L->Len + 1)
return ERROR;
if(i <= L->Len)
{
for( k = L->Len - 1;k >= i - 1; k--)
L->Elem[k+1] = L->Elem[k];
}
L->Elem[i - 1] = e;
L->Len++;
return OK;
}
//---------------删除某个元素-------------------
Status ListDelete(SqList *L,int i,int *e)
{
int k;
if(L->Len == 0)   //线性表为空
return ERROR;
if( i <1 || i > L->Len)
return ERROR; //删除的位置不正确
*e = L->Elem[i - 1];
if(i < L->Len)
{
for( k  = i;k < L->Len;k++)
L->Elem[k-1] = L->Elem[k];
}
L->Len--;
return OK;
}

int main(void)
{
SqList L;
int k,a;
// 构造线性表
printf("构造线性表\n");
InitList(&L);
// 初始化线性表
printf("初始化线性表\n");
L.Len = 5;
printf("请输入5个元素\n");
for(k = 0;k < L.Len; k++)
scanf("%d",&L.Elem[k]);
// GetElem(L,2,&a);
// printf("%d\n",a);
// ListInsert(&L,3,9);
// 删除第4个元素
printf("删除第4个元素\n");
ListDelete(&L,4,&a);
// 输出被删除的元素
printf("输出被删除的元素\n");
printf("%d\n",a);
// 遍历输出线性表
printf("遍历输出线性表\n");
for(k = 0; k < L.Len; k++)
printf("%d ",L.Elem[k]);
printf("\n");


return 0;
}

