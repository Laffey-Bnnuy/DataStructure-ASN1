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
char* randomizeUsername() {
	char* result = malloc(MAX_NAME);
	char buffer[MAX_NAME];
	for (int i = 0; i < MAX_NAME; i++) {
		buffer[i] = randomChar();
	}
	strncpy(result, buffer, MAX_NAME);
	result[10] = '\0';
	return result;
}
int randomlyGeneratedUser(USERSTAT* data) {
	char faction[3][MAX_NAME] = { "red","blue","green" };

	strncpy(data->faction, faction[(rand() % 3)], MAX_NAME);
	strncpy(data->username, randomizeUsername(), MAX_NAME);
	data->level = rand() % 61;

}