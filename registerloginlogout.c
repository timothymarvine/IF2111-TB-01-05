#include <stdio.h>
#include <stdlib.h>

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
    system->currentSession[0] = '\0';
}

int stringLength(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int stringCompare(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0; 
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void stringCopy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void readLine(char *buffer, int maxLength) {
    int i = 0;
    char ch;
    while (i < maxLength - 1 && (ch = getchar()) != '\n' && ch != EOF) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
}

int isUsernameTaken(System *system, const char *username) {
    for (int i = 0; i < system->userCount; i++) {
        if (stringCompare(system->users[i].username, username)) {
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
        stringCopy(system->users[system->userCount].username, username);
        stringCopy(system->users[system->userCount].password, password);
        system->userCount++;
        printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    } else {
        printf("Sistem penuh, tidak bisa menambahkan akun baru.\n");
    }
}

int findUser(System *system, const char *username, const char *password) {
    for (int i = 0; i < system->userCount; i++) {
        if (stringCompare(system->users[i].username, username) &&
            stringCompare(system->users[i].password, password)) {
            return 1; 
        }
    }
    return 0;
}

void login(System *system, const char *username, const char *password) {
    if (system->currentSession[0] != '\0') {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", system->currentSession);
        return;
    }

    if (findUser(system, username, password)) {
        stringCopy(system->currentSession, username);
        printf("Anda telah login ke PURRMART sebagai %s.\n", username);
    } else {
        printf("Username atau password salah.\n");
    }
}

void logout(System *system) {
    if (system->currentSession[0] == '\0') {
        printf("Tidak ada sesi login yang aktif.\n");
        return;
    }

    printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", system->currentSession);
    system->currentSession[0] = '\0';
}

int main() {
    System system;
    initializeSystem(&system);

    char command[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    while (1) {
        printf("\n>> "); // Prompt command
        readLine(command, MAX_LENGTH);

        if (stringCompare(command, "REGISTER")) {
            printf("Username: ");
            readLine(username, MAX_LENGTH);

            printf("Password: ");
            readLine(password, MAX_LENGTH);

            registerUser(&system, username, password);

        } else if (stringCompare(command, "LOGIN")) {
            printf("Username: ");
            readLine(username, MAX_LENGTH);

            printf("Password: ");
            readLine(password, MAX_LENGTH);

            login(&system, username, password);

        } else if (stringCompare(command, "LOGOUT")) {
            logout(&system);

        } else if (stringCompare(command, "EXIT")) {
            printf("Keluar dari sistem PURRMART.\n");
            break;

        } else {
            printf("Command tidak dikenali. Gunakan REGISTER, LOGIN, LOGOUT, atau EXIT.\n");
        }
    }

    return 0;
}
