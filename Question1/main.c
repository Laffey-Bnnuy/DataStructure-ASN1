#include "queue.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>
#define INVALID_USER_NUM -3
int main(int argc,char *argv[]) {
    
    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Invalid user number input\n");
        return INVALID_USER_NUM;
    }
    QUEUE q;
    initiateQueue(&q);

    if (enqueueRandomUsers(&q, n) != 0) {
        fprintf(stderr, "Error enqueuing users\n");
        return ENQUEUE_FAIL;
    }
    USERSTAT user;
    PNODE temp;
    while (!isQueueEmpty(&q)) {
        temp = deQueue(&q, &user);
        if (temp != NULL) {
            printf("Username: %s\nLevel: %d\nFaction: %s\n---------\n", user.username, user.level, user.faction);
            free(temp);
        }
       
    }
    

    return 0;
}