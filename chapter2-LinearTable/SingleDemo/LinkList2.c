/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: gaoziqiang
 *
 * Created on 2017年10月20日, 下午2:50
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//线性表的单链表存储结构

typedef struct LNode {
    ElemType data; //数据域
    int length;
    struct LNode *next; //指针域
} LNode, *LinkList;

void CreateLinkList(LNode *L, int n) {

    int i;

    L = (LinkList) malloc(sizeof (LNode));
    L->next = NULL;
    printf("***链表创建中***\n");
    for (i = n; i > 0; --i) {

        printf("请输入第 %d 个元素:\n", 6 - i);
        LNode *p;
        p = (LinkList) malloc(sizeof (LNode)); // 创建节点
        
        scanf("%d", &p->data);
        ++L->length;
        p->next = L->next;
        L->next = p;
        printf("打印元素%d:%d \n",6 - i,p->data);
    }
    printf("length:%d\n",L->length);
    printf("***链表创建完毕***\n");
}

void TraverseList(LNode *L) {
    
    LNode *p;
    p = L->next;
    printf("打印L->next%p\n",L->next);
    printf("打印p%p\n",p);
    printf("打印p.data%d\n",p->data);
    //p = L->next;
    printf("***开始遍历***\n");
    while(p != NULL) {
        printf("test1");
        printf("%d\n",p->data);
        printf("test2");
        p = p->next;
        printf("test3");
    } 
    
    printf("***遍历结束***\n");
        
}
/*
 * 
 */
int main() {

    printf("Hello World!\n");

    LNode L;

    int n = 5;

    CreateLinkList(&L,5);
    //TraverseList(&L);

    return 0;
}


