#define _CRT_SECURE_NO_WARNINGS
#include "stat.h"
#include <stdlib.h>
#include <string.h>
char randomChar() {
	char buffer[3];
	buffer[0] = rand() % 26 + 65;
	buffer[1] = rand() % 26 + 97;
	buffer[2] = rand() % 10 + 48;
	return buffer[rand()%3];
}
static char* randomizeUsername() {
	char buffer[MAX_NAME];
	for (int i = 0; i < MAX_NAME; i++) {
		buffer[i] = randomChar();
	}
	return buffer;
}
int randomlyGeneratedUser(USERSTAT* data) {
	char faction[3][MAX_NAME] = { "red","blue","green" };
	strncpy(data->faction, faction[(rand() % 3)], MAX_NAME);
	strncpy(data->username, randomizeUsername(), MAX_NAME);
	data->username[MAX_NAME] = '\0';
	data->level = rand() % 60 + 1 ;

}	