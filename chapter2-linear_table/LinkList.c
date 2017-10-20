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


void CreatLinkList(LinkList *L, int n) {

    int i;
    
    L = (LinkList) malloc(sizeof (LNode));
    L->next = NULL;
    for (i = n; i > 0; --i) {
        LinkList p = (LinkList) malloc(sizeof (LNode));
        scanf(&p->data);
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

    LinkList L;
    
    int n = 5;
    
    CreatLinkList(&L,5);
    return 0;
}


