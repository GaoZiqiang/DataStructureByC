#include <stdio.h>
#include <stdlib.h>
#define OK 1;
#define OVERFLOW -2
#define MAXSIZE 100//顺序表可能达到的最大长度
typedef int Status;//Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int ElemType;//ElemType是线性表中数据元素的类型，此处用int
typedef struct
{
    ElemType *elem;//存储空间的基地址
    int length;//当前长度
    int listsize;//当前分配的存储容量
}SqList;
Status InitList_Sq(SqList *L)//构造一个空的顺序表
{
    L.elem=new ElemType[MAXSIZE];//为顺序表分配一个大小为MAXSIZE的数组空间
    if(!L.elem) exit(OVERFLOW);//存储失败
    L.length=0;//空表长度为零
    L.listsize=MAXSIZE;
    return OK;
}
Status ListTraverse(SqList L)//  初始条件：顺序线性表L已存在
{
    ElemType *p;
    p=L.elem;
    int i;
    printf("线性表当前容量为：%d\n",L.listsize);
    if(L.length>0)
    {
        printf("当前线性表有%d个元素,分别是\n",L.length);
        for(i=1;i<=L.length;i++)
        {
            printf("%d ",*p++);
        }
    }
    else
    {
        printf("目前还是空线性表.\n");
    }
}
int main()
{
    SqList la;
    InitList_Sq(la);
    ListTraverse(la);
}
