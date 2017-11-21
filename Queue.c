//
// Created by MrRightli on 2017/11/21.
//
/*
 * 队列:一种可以实现"先进先出"的存储结构
 *
 * 分类:  链式队列 -- 用了链表实现
 *
 *        静态队列 -- 用数组实现
 *          静态队列通常都必须是循环队列,
 *          循环队列:
 *              1. 静态队列卫视必须是循环队列
 *              2. 循环队列需要几个参数
 *                  front
 *                  rear
 *              3. 循环队列各个参数的含义
 *                  1). 队列初始化
 *                          front 额值都是零
 *                  2). 队列非空
 *                      front 代表的事队列的第一个元素
 *                      rear 代表的事队列的最后一个有效元素的下一位地址
 *                  3). 队列空
 *                      front rear 的值相等,但不一定是零
 *              4. 循环队列的伪算法
 *                  1). 入队列
 *                  2). 出队列
 *                      f = (f+1) % 数组的长度
 *              5. 如何判断循环队列是否为空
 *                  如果 front 与 rear 的值相等,则该队列一定为空
 *              6. 如何判断循环队列已满
 *                  if ((r+1)%数组长度 == f) {
 *                      已满
 *                  } else {
 *                      不满
 *                  }
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
    int *pBase;
    int front;
    int rear;
} QUEUE;

void init(QUEUE *);

bool en_queue(QUEUE *, int);
bool full_queue(QUEUE *);
bool empty_queue(QUEUE *);
bool out_queue(QUEUE *, int *);

void traverse_queue(QUEUE *);

int main(int argc, const char *argv[]) {
    QUEUE Q;

    init(&Q);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);

    traverse_queue(&Q);

    int outVal;
    out_queue(&Q, &outVal);
    printf("出队的数值为:%d\n",outVal);
}

void init(QUEUE *pQ) {
    pQ->pBase = (int *) malloc(sizeof(int) * 6);
    pQ->front = 0;
    pQ->rear = 0;
}

/**
 * 入队
 * @param pQ
 * @param val
 * @return
 */
bool en_queue(QUEUE *pQ, int val) {
    if (full_queue(pQ))
        return false;

    pQ->pBase[pQ->rear] = val;
    pQ->rear = (pQ->rear + 1) % 6;
}

/**
 * 出队
 * @param pQ
 * @param pVal
 * @return
 */
bool out_queue(QUEUE *pQ, int * pVal) {
    if (empty_queue(pQ))
        return false;

    *pVal = pQ->pBase[pQ->front];
    pQ->front = (pQ->front + 1) % 6;

    return true;
}
/**
 * 队列是否满
 * @param pQ
 * @return
 */
bool full_queue(QUEUE *pQ) {
    if (pQ->rear + 1 == pQ->front) {
        return true;
    } else {
        return false;
    }
}
/**
 * 队列是否为空
 * @param pQ
 * @return
 */
bool empty_queue(QUEUE *pQ) {
    if (pQ->rear% 6 == pQ->front) {
        return true;
    } else {
        return false;
    }
}

/**
 * 遍历队列
 * @param pQ
 */
void traverse_queue(QUEUE *pQ) {
    int i = pQ->front;
    while (i != pQ->rear) {
        printf("%d ", pQ->pBase[i]);
        i = (i + 1) % 6;
    }
    printf("\n");
}
