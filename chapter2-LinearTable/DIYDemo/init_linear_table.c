/*线性表的构造、初始化、元素插入、删除、遍历*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 2 // 线性表初始分配存储空间
#define LIST_INCREMENT 50 // 线性表追加存储空间

typedef int Status;// 函数返回值类型
typedef int ElemType;// 主要处理元素类型

/*线性表的存储结构*/
typedef struct {
   ElemType *elem;// 存储空间基址
   int length;// 长度
   int list_size;// 存储空间
}SqList;

/*函数调用声明*/
Status init_list(SqList *L);
Status insert_list(SqList *L,int i,ElemType e);
Status delete_list(SqList *L,int i,ElemType *e);
Status ergodic_list(SqList *L);
Status get_elem(SqList *L,int i);
Status locate_elem(SqList *L,ElemType e);
int main()
{

    /*总结：在单个方法内部，调用结构体变量用L->elem;在main方法中，调用结构体变量用L.elem*/
    SqList L;
    int k,l;

    int i,e;// 插入元素的位置和数值
    int j;// 删除元素的位置
    /*1.构造线性表*/
    printf("***1.构造线性表***\n");

    init_list(&L);
    /*2.初始化线性表*/
    printf("***2.初始化线性表***\n");
    printf("---请确定线性表的长度---\n");
    scanf("%d",&l);
    for(k = 0;k < l;k++) {
        printf("请输入第%d个元素:\n",k + 1);
        scanf("%d",&(L.elem[k]));// 为什么不能使用L->elem[k]?
        L.length++;// 记住，这里的L.length不是自动增加的，需要手动增加，不同于L.size
    }
    printf("***初始化线性表成功***\n");

    /*遍历输出*/
    // printf("---遍历输出---\n");
    printf("L.length: %d\n",L.length);
    printf("L.size: %d\n",L.list_size);
    printf("---遍历输出---\n");
    ergodic_list(&L);
    /*3.插入元素*/
    /*
    printf("***3.插入元素***\n");
    printf("---确定插入元素的位置---\n");
    scanf("%d",&i);
    printf("---输入插入元素的数值---\n");
    scanf("%d",&e);
    insert_list(&L,i,e);
    */

    /*4.删除元素*/
    /*
    printf("***4.删除元素***\n");
    printf("---确定要删除元素的位置---\n");
    scanf("%d",&i);
    delete_list(&L,i,&e);
    */

    /*5.查找元素*/
    /*
    printf("***5.查找元素***\n");
    printf("---请输出要查找的元素位置---\n");
    scanf("%d",&i);
    get_elem(&L,i);
    */

    /*6.查找元素位置*/
    printf("***6.查找元素位置***\n");
    printf("---请输入要查找的元素---\n");
    scanf("%d",&i);
    locate_elem(&L,i);
    /*6.再次遍历输出*/
    printf("L.length: %d\n",L.length);
    ergodic_list(&L);
    /*
    printf("---再次遍历输出---\n");
    for(k = 0;k < L.length;k++) {
    printf(" %d",L.elem[k]);
    }
    printf("\n");
    return OK;
    */
}

/*线性表初始化*/
Status init_list(SqList *L) {
   /*构造一个空的线性表（分配内存空间）*/
   L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));// L->elem,线性表的基址base
   /*判断是否初始化成功*/
   if(!L->elem) {
      printf("---初始化失败---\n");
      exit(ERROR);
   }
   L->length = 0;// 初始长度
   L->list_size = LIST_INIT_SIZE;// 初始存储容量

   printf("***构造线性表成功***\n");

   return OK;
}
/*插入元素*/
Status insert_list(SqList *L,int i,ElemType e) {
   // 在线性表的第i个位置之前插入元素e
   // i的合法值1=<i<=list_length+1
   /*定义变量*/
   // printf("---测试：插入元素---\n");
   ElemType *q,*p;
   ElemType *new_base;

   if(i < 1 || i > (L->length + 1)) {
      printf("---您要插入的元素超出线性表长度---\n");
      return ERROR;
   }
   /*存储空间判断*/
   if(L->length >= L->list_size) {// 当前存储空间已满,增加分配
      printf("---当前存储空间已满，追加存储空间---\n");
      new_base = (ElemType *)realloc(L->elem,(L->list_size + LIST_INCREMENT) * sizeof(ElemType));

   if(!new_base)
       exit(ERROR);
   /*新基址*/
   L->elem = new_base;
   /*新存储容量*/
   L->list_size += LIST_INCREMENT;
   printf("---追加存储空间成功---\n");
   }

   // printf("---测试2：插入元素---\n");
   q = &(L->elem[i - 1]);// q为插入位置
   /*将插入元素位置以后的所有元素后移*/
   for(p = &(L->elem[L->length - 1]);p>=q;--p)
       /*元素后移,依次向前取代*/
       *(p + 1) = *p;
   /*直到q之后的所有元素都后移完后,将e元素插入到q的位置*/
   *q = e;
   /*表长增加1*/
   ++L->length;

    printf("***插入元素成功***\n");

   return OK;
}
/*删除元素*/
Status delete_list(SqList *L,int i,ElemType *e) {// 为什么要用指针变量*e?
   // 删除第i个元素
   // i的合法值为1<=i<=list_length
   /*定义变量*/
   ElemType *p,*q;

   if(i < 1 || i > L->length) {
      printf("---超出线性表的长度---\n");

      return ERROR;
   }

   /*获取待删除元素的位置*/
   q = &(L->elem[i - 1]);
   /*将待删除的元素赋值给e*/
   e = *q;
   /*输出基址*/
   // printf("---输出基址---%d\n",L->elem);
   /*将表尾元素的位置赋值给p*/
   p = L->elem + L->length - 1;// 为什么要这样求表尾元素?
   /*待删除元素之后的所有元素左移（前移）*/
   for(++q;q <= p;++q)
       *(q - 1) = *q;
   /*表长减1*/
   --L->length;

   printf("***删除元素成功***\n");

   return OK;
}
/*通过元素位置查找元素*/
Status get_elem(SqList *L,int i) {
   // 通过元素位置i查找元素e
   /*定义临时变量*/
   ElemType *flag;
   // i的合法值1=<i<=list_length+1
   if(i < 1 || i > (L->length + 1)) {
      printf("---您要查找的元素超出线性表长度---\n");
      return ERROR;
   }
   /*将待查找的元素赋值给e*/
   // *flag = L->elem[L->elem + i - 1];
   *flag = *(L->elem + i - 1);// 要查找的元素
   //*flag = L->elem[flag];
   /*将元素输出*/
   printf("---您要查找的元素: %d\n",*flag);
}
/*查找元素位置*/
Status locate_elem(SqList *L,ElemType e) {
   int i;
   int result = 0;// 判断是否存在该元素的flag
   ElemType *flag;

   i = 1;// i的初始值为第1个元素的位序
   flag = L->elem;// flag的初始值为第1个元素的存储位置
   while(i <= L->length) {
      if(*flag == e) {
         // printf("---要查找的元素位置为: %d\n",i);
         result = i;
      }
      *flag++;
      ++i;
   }

   if(result == 0) {
      printf("---要查找的元素不存在---");
   }else {
      printf("---要查找的元素位置为: %d\n",result);
   }

   return OK;
}
/*遍历元素*/
Status ergodic_list(SqList *L) {
   int k;
   printf("---遍历输出---\n");
   for(k = 0;k < L->length;k++) {
    printf(" %d",L->elem[k]);
   }
   printf("\n");

   return OK;
}
