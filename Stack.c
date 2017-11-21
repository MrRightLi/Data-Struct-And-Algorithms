//
// Created by MrRightli on 2017/11/16.
//
/*
 * 应用:
 * 函数调用,中断,表达式求值,内存分配,缓存处理,迷宫
 */

#include <stdio.h>
#include <stdlib.h>
#import <stdbool.h>

typedef struct Node {
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack {
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK, int);
bool pop(PSTACK, int *);
bool empty(PSTACK);
void clear(PSTACK);

void traverse(PSTACK);

int main(int argc, const char *argv[]) {
    STACK S;

    init(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    traverse(&S);

    int popVal;
    pop(&S, &popVal);
    printf("出栈的数值为:% d \n",popVal);

    clear(&S);
    push(&S, 5);
    traverse(&S);
}

/**
 * 栈的初始化
 * @param pS
 */
void init(PSTACK pS) {
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (NULL == pS->pTop) {
        printf("动态内存分配失败");
        exit(-1);
    } else {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
}

/**
 * 压栈
 * @param pS
 * @param val
 */
void push(PSTACK pS, int val) {
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

/**
 * 出栈
 * @param pS
 * @param val
 * @return
 */
bool pop(PSTACK pS, int *val) {
    if (empty(pS)) {
        return false;
    }

    PNODE r = pS->pTop;
    *val = r->data;
    pS->pTop = r->pNext;
    free(r);
    r = NULL;
    return true;
}
/**
 * 请空栈
 * @param pS
 */
void clear(PSTACK pS) {
    if (empty(pS)) {
        return;
    } else {
        PNODE p = pS->pTop;
        PNODE q = p->pNext;

        while (p != pS->pBottom) {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom;
    }
}

bool empty(PSTACK pS) {
    if (pS->pTop == pS->pBottom)
        return true;
    else
        return false;
}

/**
 * 遍历栈
 * @param pS
 */
void traverse(PSTACK pS) {
    PNODE p = pS->pTop;
    while (p != pS->pBottom) {
        printf("%d ",p->data);
        p = p->pNext;
    }
    printf("\n");
}