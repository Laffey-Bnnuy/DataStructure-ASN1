#include <stdio.h>
#pragma once
#include "stat.h"
#define MEM_ALLOT_FAIL -1
#define ENQUEUE_FAIL -2
typedef struct node {
	struct node* pNext; 
	USERSTAT data;
}NODE,*PNODE;
typedef struct {
	struct node* pHead;         
	struct node* pTail;         
} QUEUE;


int enqueueRandomUsers(QUEUE* q, int n);
void initiateQueue(QUEUE*q);
int isQueueEmpty(QUEUE* q);
int addToQueue(QUEUE* q, USERSTAT data);
PNODE deQueue(QUEUE* q,USERSTAT* user);
