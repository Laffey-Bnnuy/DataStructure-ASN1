#include <stdio.h>
#pragma once
#include "stat.h"
typedef struct node {
	struct node* pNext; 
	USERSTAT data;
}NODE,*PNODE;
typedef struct {
	struct node* pHead;         
	struct node* pTail;         
} QUEUE;



void initiateQueue(QUEUE);
int isQueueEmpty(void); 
int addToQueue(USERSTAT data);
PNODE deQueue(void); 
