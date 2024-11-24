#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

#define MAX_USERS 100
#define MAX_LENGTH 100
typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

typedef struct {
    User users[MAX_USERS];
    int totalUsers;
    char activeUser[MAX_LENGTH];
} System;

void initializeSystem(System *sys) {
    sys->totalUsers = 0;
    sys->activeUser[0] = '\0';
}

int isUsernameTaken(System *sys, const char *username) {
    for (int i = 0; i < sys->totalUsers; i++) {
        if (isWordEqual(username, sys->users[i].username)) {
            return 1;
        }
    }
    return 0;
}

void registerUser(System *sys, const char *username, const char *password) {
    if (isUsernameTaken(sys, username)) {
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
        return;
    }

    if (sys->totalUsers < MAX_USERS) {
        for(int i = 0; i < MAX_LENGTH; i++){
            if(username[i] == '\0' || username[i] == '\n') break;
            sys->users[sys->totalUsers].username[i] = username[i];
        }
        for(int i = 0; i < MAX_LENGTH; i++){
            if(password[i] == '\0' || username[i] == '\n') break;
            sys->users[sys->totalUsers].password[i] = password[i];
        }
        sys->totalUsers++;
        printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    } else {
        printf("Sistem penuh, tidak bisa menambahkan akun baru.\n");
    }
}

int findUser(System *sys, const char *username, const char *password) {
    for (int i = 0; i < sys->totalUsers; i++) {
        if (isWordEqual(username, sys->users[i].username) && isWordEqual(password, sys->users[i].password)) {
            return 1;
        }
    }
    return 0;
}

void loginUser(System *sys, const char *username, const char *password, int *loggedIn) {
    if (sys->activeUser[0] != '\0') {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", sys->activeUser);
        return;
    }

    if (findUser(sys, username, password)) {
        // CopyWord(sys->activeUser);
        printf("Anda telah login ke PURRMART sebagai %s.\n", username);
        *loggedIn = 1;
    } else {
        printf("Username atau password salah.\n");
    }
}

void logoutUser(System *sys, int *isLoggedIn) {
    printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", sys->activeUser);
    sys->activeUser[0] = '\0';
    *isLoggedIn = 0;
}
