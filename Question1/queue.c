#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
#include "stat.h"
#include <string.h>
#include <stdlib.h>
#define MEM_ALLOT_FAIL -1
#define ENQUEUE_FAIL -2
int enqueueRandomUsers(QUEUE *q,int n) {
	USERSTAT data;
	for (int i = 0; i < n; i++) {
		randomlyGeneratedUser(&data);
		if (addToQueue(q,data) != 0) {
			return ENQUEUE_FAIL;
		}
	}
	return 0;
}
void initiateQueue(QUEUE *q) {
	q->pHead = NULL;
	q->pTail = NULL;
}

	
int isQueueEmpty(QUEUE *q) {
	return (q->pHead == NULL);
}
int addToQueue(QUEUE * q,USERSTAT data) {
	PNODE newNode = (PNODE)malloc(sizeof(NODE));
	if (!newNode) {
		fprintf(stderr, "Error allocating memory");
		return MEM_ALLOT_FAIL;
	}

	newNode->data = data;
	newNode->pNext = NULL;

	if (isQueueEmpty(q)) {
		q->pHead = q->pTail = newNode;
	}
	else {
		q->pTail->pNext = newNode;
	}
	q->pTail = newNode;
	return 0;
}
PNODE deQueue(QUEUE *q){
	PNODE temp;
	if (isQueueEmpty(q))
		return(NULL); 
	temp = q->pHead; 
	q->pHead = q->pHead->pNext; 
	return(temp); 
}