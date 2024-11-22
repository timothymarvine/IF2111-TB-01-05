#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

typedef struct {
    User users[MAX_USERS];
    int userCount;
    char currentSession[MAX_LENGTH];
} System;

void initializeSystem(System *system) {
    system->userCount = 0;
    strcpy(system->currentSession, "");
}

int findUser(System *system, const char *username, const char *password) {
    for (int i = 0; i < system->userCount; i++) {
        if (strcmp(system->users[i].username, username) == 0 &&
            strcmp(system->users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void login(System *system, const char *username, const char *password) {
    if (strcmp(system->currentSession, "") != 0) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", system->currentSession);
        return;
    }

    if (findUser(system, username, password)) {
        strcpy(system->currentSession, username);
        printf("Anda telah login ke PURRMART sebagai %s.\n", username);
    } else {
        printf("Username atau password salah.\n");
    }
}

int main() {
    System system;
    initializeSystem(&system);

    strcpy(system.users[0].username, "johndoe");
    strcpy(system.users[0].password, "janedoe");
    system.userCount++;

    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    login(&system, username, password);

    return 0;
}
