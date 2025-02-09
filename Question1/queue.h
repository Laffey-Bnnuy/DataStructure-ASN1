#include <stdio.h>
#pragma once
#include "stat.h"
typedef struct node {
	struct node* pNext; 
	USERSTAT data;
}NODE,*PNODE;

PNODE pHead;
PNODE pTail;

PNODE createNode();
void initiateQueue(void);
int isQueueEmpty(void); 
void AddToQueue(PNODE); 
PNODE deQueue(void); 
int randomlyGeneratedUser(PUSERSTAT);