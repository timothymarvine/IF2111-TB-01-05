#include <stdio.h>
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "REGISTER.h"

void RegisterAccount() {
    Total userDatabase;
    char username[50], password[50];
    
    printf("Username: ");
    STARTWORD2();
    int i = 0;
    while (currentWord.TabWord[i] != '\0') {
        username[i] = currentWord.TabWord[i];
        currentWord.TabWord[i] = '\0';
        i++;
    }
    username[i] = '\0';
    
    printf("Password: ");
    STARTWORD2();
    int j = 0;
    while (currentWord.TabWord[j] != '\0') {
        password[j] = currentWord.TabWord[j];
        currentWord.TabWord[j] = '\0';
        j++;
    }
    password[j] = '\0';

    for (int k = 0; k < 50; k++) {
        if (isEqual(username, userDatabase.TotUs[k].name)) {
            if (isEqual(password, userDatabase.TotUs[k].password)) {
                printf("Login Berhasil!\n");
                login = true;
                for (int l = 0; username[l] != '\0'; l++) {
                    name[l] = username[l];
                }
                name[i] = '\0';
                return;
            }
        }
    }
    printf("Username/Password salah!\n");
    MULAI();
}
