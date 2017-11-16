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

bool insert_list(PNODE, int, int);

int delete_list(PNODE, int, int *);

void sort_list(PNODE pHead);

int main(int argc, const char *argv[]) {
    PNODE pHead = NULL;
    pHead = create_list();
    if (is_empty(pHead)) {
        printf("链表为空 \n");
    }

    int length = length_list(pHead);
    printf("链表长度为: %d \n", length);

    insert_list(pHead, 4, 10);
    traverse_list(pHead);

    sort_list(pHead);

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

/**
 * 遍历数组
 * @param pHead
 */
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

/**
 * 链表的冒泡排序
 * @param pHead
 */
void sort_list(PNODE pHead) {
    int i, j ,t;
    PNODE p, q;
    int len = length_list(pHead);
    for (i = 0, p = pHead->pNext; i < len - 1; ++i, p = p->pNext) {
        for (j = i+1, q = p->pNext; j < len; ++j, q = q->pNext) {
            if (p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}

/**
 * 链表插入数值
 * @param pHead
 * @param pos 位置,从1开始
 * @param val 值
 * @return
 */
bool insert_list(PNODE pHead, int pos, int val) {
    int i = 0;
    PNODE p = pHead;

    // 保证 pos 在有效位置
    while (NULL != p && i < pos-1) {
        p = p->pNext;
        ++i;
    }

    if (i > pos - 1 || NULL == p) {
        return false;
    }

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew) {
        printf("动态内存分配失败! \n");
        exit(-1);
    }

    pNew->data = val;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;

    return true;
}
