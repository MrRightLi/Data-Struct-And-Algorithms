#include <stdio.h>
#include <stdlib.h>
#import <stdbool.h>

typedef struct Node {
    int data; // 数据域
    struct Node *pNext; // 指针域
} NODE, *PNODE;


PNODE create_list(void);

void traverse_list(PNODE pHead);

bool is_empty(PNODE pHead);

int length_list(PNODE);

int insert_list(PNODE, int, int);

int delete_list(PNODE, int, int *);
//bool is_empty(PNODE pHead);


int main(int argc, const char *argv[]) {
    PNODE pHead = NULL;
    pHead = create_list();
    traverse_list(pHead);
    if (is_empty(pHead)) {
        printf("链表为空 \n");
    }

    int length = length_list(pHead);
    printf("链表长度为: %d \n", length);


    return 0;
}

PNODE create_list(void) {
    int len;
    int val;

    PNODE pHead = (PNODE) malloc(sizeof(NODE));
    if (pHead == NULL) {
        printf("内存分配! \n失败");
        exit(-1);
    }

    printf("请输入链表节点个数: len = ");
    scanf("%d", &len);


    PNODE pTail = pHead;
    pTail->pNext = NULL;

    for (int i = 0; i < len; i++) {
        printf("请输入第 %d 个节点的值:", i + 1);
        scanf("%d", &val);

        PNODE pNEW = (PNODE) malloc(sizeof(NODE));
        pNEW->data = val;
        pNEW->pNext = NULL;

        pTail->pNext = pNEW;

        pTail = pNEW;
    }

    return pHead;
}

void traverse_list(PNODE pHead) {
    PNODE p = pHead->pNext;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

bool is_empty(PNODE pHead) {
    if (NULL == pHead->pNext) {
        return true;
    } else {
        return false;
    }
}

/**
 *  数组长度
 * @param pHead
 * @return
 */
int length_list(PNODE pHead) {
    PNODE p = pHead->pNext;
    int len = 0;
    while (NULL != p) {
        ++len;
        p = p->pNext;
    }
    return len;
}