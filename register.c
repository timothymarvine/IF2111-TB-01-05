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
} System;

void initializeSystem(System *system) {
    system->userCount = 0;
}

int isUsernameTaken(System *system, const char *username) {
    for (int i = 0; i < system->userCount; i++) {
        if (strcmp(system->users[i].username, username) == 0) {
            return 1;
        }
    }
    return 0;
}

void registerUser(System *system, const char *username, const char *password) {
    if (isUsernameTaken(system, username)) {
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
        return;
    }
    if (system->userCount < MAX_USERS) {
        strcpy(system->users[system->userCount].username, username);
        strcpy(system->users[system->userCount].password, password);
        system->userCount++;
        printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    } else {
        printf("Sistem penuh, tidak bisa menambahkan akun baru.\n");
    }
}

int main() {
    System system;
    initializeSystem(&system);

    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    registerUser(&system, username, password);

    return 0;
}
