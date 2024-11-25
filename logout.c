#include "LOGOUT.h"

char name[50];
char password[50];
int money;
boolean login;

void LogoutUser() {
    if (login) {
        for (int i = 0; name[i] != '\0'; i++) {
            name[i] = '\0';
        }
        for (int i = 0; password[i] != '\0'; i++) {
            password[i] = '\0';
        }
        money = NIL;
        login = false;
        printf("Logout berhasil!\n");
    } else {
        printf("Kamu belum login. Silakan login terlebih dahulu!\n");
        MULAI();
    }
}
