#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
#include "stat.h"
#include <string.h>
#include <stdlib.h>

PNODE createNode() {
	char faction[3][MAX_NAME] = {"red","blue","green"};
	
	PNODE newNode = (PNODE)malloc(sizeof(NODE));
	if (!newNode) {
		fprintf(stderr, "error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	strncpy(newNode->data.faction, faction[(rand() % 3)],MAX_NAME);
	strncpy(newNode->data.username,randomizeUsername(), MAX_NAME);
	newNode->data.level = rand() % 61;
	
	return newNode;
}
void initiateQueue(void) {
	pHead = pTail = NULL;
}
int randomlyGeneratedUser(USERSTAT *data) {
	char faction[3][MAX_NAME] = { "red","blue","green" };

	strncpy(data->faction, faction[(rand() % 3)], MAX_NAME);
	strncpy(data->username, randomizeUsername(), MAX_NAME);
	data->level = rand() % 61;

}
	
int isQueueEmpty(void) {
	return (pHead == NULL);
}
void addToQueue(PNODE node) {
	if (pHead == NULL) {
		pHead = pTail = node;
	}
	else {
		pTail->pNext = node;
	}
	node->pNext = NULL;
	pTail = node;
}
PNODE deQueue(void){
	PNODE temp;
	if (pHead == NULL) return(NULL); 
	temp = pHead; 
	pHead = pHead->pNext; 
	return(temp); 
}