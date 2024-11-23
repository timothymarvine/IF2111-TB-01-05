#include <stdio.h>
#include <stdlib.h>
#include "mesin_kata.h"

#define MAX_USERS 100

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
        if (isWordEqual(username)) {
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
        copyCurrentWord(sys->users[sys->totalUsers].username);
        copyCurrentWord(sys->users[sys->totalUsers].password);
        sys->totalUsers++;
        printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    } else {
        printf("Sistem penuh, tidak bisa menambahkan akun baru.\n");
    }
}

int findUser(System *sys, const char *username, const char *password) {
    for (int i = 0; i < sys->totalUsers; i++) {
        if (isWordEqual(username) && isWordEqual(password)) {
            return 1;
        }
    }
    return 0;
}

void loginUser(System *sys, const char *username, const char *password) {
    if (sys->activeUser[0] != '\0') {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", sys->activeUser);
        return;
    }

    if (findUser(sys, username, password)) {
        copyCurrentWord(sys->activeUser);
        printf("Anda telah login ke PURRMART sebagai %s.\n", username);
    } else {
        printf("Username atau password salah.\n");
    }
}

void logoutUser(System *sys) {
    if (sys->activeUser[0] == '\0') {
        printf("Tidak ada sesi login yang aktif.\n");
        return;
    }

    printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", sys->activeUser);
    sys->activeUser[0] = '\0';
}

int main() {
    System system;
    initializeSystem(&system);

    while (1) {
        printf("\n>> ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        startInput(inputBuffer);
        startWord();

        if (isWordEqual("REGISTER")) {
            startWord();
            char username[MAX_LENGTH];
            copyCurrentWord(username);

            startWord();
            char password[MAX_LENGTH];
            copyCurrentWord(password);

            registerUser(&system, username, password);

        } else if (isWordEqual("LOGIN")) {
            startWord();
            char username[MAX_LENGTH];
            copyCurrentWord(username);

            startWord();
            char password[MAX_LENGTH];
            copyCurrentWord(password);

            loginUser(&system, username, password);

        } else if (isWordEqual("LOGOUT")) {
            logoutUser(&system);

        } else if (isWordEqual("EXIT")) {
            printf("Keluar dari sistem PURRMART.\n");
            break;

        } else {
            printf("Command tidak dikenali. Gunakan REGISTER, LOGIN, LOGOUT, atau EXIT.\n");
        }
    }

    return 0;
}
