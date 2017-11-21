//
// Created by MrRightli on 2017/11/16.
//

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

void push(PSTACK pS, int val) {
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

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

void clear(PSTACK pS)
{
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

void traverse(PSTACK pS) {
    PNODE p = pS->pTop;
    while (p != pS->pBottom) {
        printf("%d ",p->data);
        p = p->pNext;
    }
    printf("\n");
}