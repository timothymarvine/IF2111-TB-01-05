#include <stdio.h>
#include <stdlib.h>
#include "ADT\mesinkata\mesinkata.h"
#include "rll.h"

void initializeSystem(System *sys) {
    sys->totalUsers = 0;
    sys->activeUser[0] = '\0';
}

int isUsernameTaken(System *sys, const char *username, User user[]) {
    boolean status = false;
    for (int i = 0; i < sys->totalUsers; i++) {
        if (isWordEqual(username, sys->users[i].username)) {
            status = true;
        }
        if (isWordEqual(username, user[i].namaUser)){
            return status && 1;
        }
    }
    return 0;
}

void registerUser(System *sys, const char *username, const char *password, User user[]) {
    if (isUsernameTaken(sys, username, user)) {
        printf("\nAkun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
        return;
    }

    if (sys->totalUsers < MAX_USERS) {
        for(int i = 0; i < MAX_LENGTH; i++){
            if(username[i] == '\0' || username[i] == '\n') break;
            sys->users[sys->totalUsers].username[i] = username[i];
            user[sys->totalUsers].namaUser[i] = username[i];
        }
        for(int i = 0; i < MAX_LENGTH; i++){
            if(password[i] == '\0' || username[i] == '\n') break;
            sys->users[sys->totalUsers].password[i] = password[i];
            user[sys->totalUsers].password[i] = password[i];
        }
        sys->totalUsers++;
        printf("\nAkun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    } else {
        printf("\nSistem penuh, tidak bisa menambahkan akun baru.\n");
    }
}

int findUser(System *sys, const char *username, const char *password, User user[]) {
    boolean status = false;
    for (int i = 0; i < sys->totalUsers; i++) {
        if (isWordEqual(username, sys->users[i].username) && isWordEqual(password, sys->users[i].password)) {
            status = true;
        }
        if (isWordEqual(username, user[i].namaUser) && isWordEqual(password, user[i].password)){
            return status && 1;
        }
    }
    return 0;
}

void loginUser(System *sys, const char *username, const char *password, int *loggedIn, User user[]) {
    if (sys->activeUser[0] != '\0') {
        printf("\nAnda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", sys->activeUser);
        return;
    }

    if (findUser(sys, username, password, user)) {
        printf("\nAnda telah login ke PURRMART sebagai %s.\n", username);
        *loggedIn = 1;
    } else {
        printf("\nUsername atau password salah.\n");
    }
}

void logoutUser(System *sys, int *isLoggedIn) {
    printf("\n%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", sys->activeUser);
    sys->activeUser[0] = '\0';
    *isLoggedIn = 0;
}
