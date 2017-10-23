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
    struct LNode *next; //指针域
} LNode, *LinkList;


void CreateLinkList(LNode *L,int n) {

    int i;
    
    L = (LinkList) malloc(sizeof (LNode));
    L->next = NULL;
    for (i = n; i > 0; --i) {

        printf("链表创建中:%d\n",i);
        LNode *p;
        p = (LinkList) malloc(sizeof (LNode));// 创建节点
        printf("链表创建成功\n");
        //printf("请输入第 " + i + "个元素:\n");
        printf("链表创建成功\n");
        scanf("%d",&p->data);
        p->next = L->next;
        L->next = p;
    }
    
    printf("链表创建成功\n");
}
/*
 * 
 */
int main() {

    printf("Hello World!\n");

    LNode L;
    
    int n = 5;
    
    CreateLinkList(&L,5);
    
    return 0;
}


