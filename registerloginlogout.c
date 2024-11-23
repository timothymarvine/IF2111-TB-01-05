#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

typedef struct {
    User userList[MAX_USERS];
    int totalUsers;
    char activeSession[MAX_LENGTH];
} System;

void initialize(System *sys) {
    sys->totalUsers = 0;
    sys->activeSession[0] = '\0'; // Tidak ada sesi aktif
}

int calculateStringLength(const char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int compareStrings(const char *a, const char *b) {
    int index = 0;
    while (a[index] != '\0' && b[index] != '\0') {
        if (a[index] != b[index]) {
            return 0; // String berbeda
        }
        index++;
    }
    return a[index] == '\0' && b[index] == '\0'; // Sama jika selesai bersamaan
}

void copyString(char *destination, const char *source) {
    int index = 0;
    while (source[index] != '\0') {
        destination[index] = source[index];
        index++;
    }
    destination[index] = '\0'; // Tambahkan null-terminator
}

void getInputLine(char *buffer, int size) {
    int i = 0;
    char c;
    while (i < size - 1 && (c = getchar()) != '\n' && c != EOF) {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}

int usernameExists(System *sys, const char *username) {
    for (int i = 0; i < sys->totalUsers; i++) {
        if (compareStrings(sys->userList[i].username, username)) {
            return 1; // Username sudah digunakan
        }
    }
    return 0; // Username tersedia
}

void registerAccount(System *sys, const char *username, const char *password) {
    if (usernameExists(sys, username)) {
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
        return;
    }
    if (sys->totalUsers < MAX_USERS) {
        copyString(sys->userList[sys->totalUsers].username, username);
        copyString(sys->userList[sys->totalUsers].password, password);
        sys->totalUsers++;
        printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    } else {
        printf("Sistem penuh, tidak bisa menambahkan akun baru.\n");
    }
}

int findUser(System *sys, const char *username, const char *password) {
    for (int i = 0; i < sys->totalUsers; i++) {
        if (compareStrings(sys->userList[i].username, username) &&
            compareStrings(sys->userList[i].password, password)) {
            return 1; // Pengguna ditemukan
        }
    }
    return 0; // Pengguna tidak ditemukan
}

void loginUser(System *sys, const char *username, const char *password) {
    if (sys->activeSession[0] != '\0') {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", sys->activeSession);
        return;
    }

    if (findUser(sys, username, password)) {
        copyString(sys->activeSession, username);
        printf("Anda telah login ke PURRMART sebagai %s.\n", username);
    } else {
        printf("Username atau password salah.\n");
    }
}

void logoutUser(System *sys) {
    if (sys->activeSession[0] == '\0') {
        printf("Tidak ada sesi login yang aktif.\n");
        return;
    }

    printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", sys->activeSession);
    sys->activeSession[0] = '\0'; // Reset sesi
}

int main() {
    System sys;
    initialize(&sys);

    char command[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    while (1) {
        printf("\n>> ");
        getInputLine(command, MAX_LENGTH);

        if (compareStrings(command, "REGISTER")) {
            printf("Username: ");
            getInputLine(username, MAX_LENGTH);

            printf("Password: ");
            getInputLine(password, MAX_LENGTH);

            registerAccount(&sys, username, password);

        } else if (compareStrings(command, "LOGIN")) {
            printf("Username: ");
            getInputLine(username, MAX_LENGTH);

            printf("Password: ");
            getInputLine(password, MAX_LENGTH);

            loginUser(&sys, username, password);

        } else if (compareStrings(command, "LOGOUT")) {
            logoutUser(&sys);

        } else if (compareStrings(command, "EXIT")) {
            printf("Keluar dari sistem PURRMART.\n");
            break;

        } else {
            printf("Command tidak dikenali. Gunakan REGISTER, LOGIN, LOGOUT, atau EXIT.\n");
        }
    }

    return 0;
}
