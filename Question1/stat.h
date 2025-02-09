#pragma once
#define MAX_NAME 10

typedef struct userMenu {
	char username[MAX_NAME];
	int level;
	char faction[MAX_NAME];
}USERSTAT;
int randomlyGeneratedUser(USERSTAT* data);
