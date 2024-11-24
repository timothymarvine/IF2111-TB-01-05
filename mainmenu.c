#include <stdio.h>
#include "menu.h"
#include "workChallenge.h"
#include "work.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "rll.h"

int main() {
    char convertwsmm[50];
    char command[10];
    int isLoggedIn = 0;
    int running = 1;
    int uang_asal = 0;
    char kesempatan;
    System system;
    initializeSystem(&system);

    while (running) {
        if (!isLoggedIn) {
            // Menampilkan Welcome Menu
            WelcomeMenu();
            STARTWORD();
            WordToString(currentWord, convertwsmm); // Menggunakan array char untuk string

            for (int i = 0; i < currentWord.Length; i++) {
                command[i] = convertwsmm[i];
            }
            command[currentWord.Length] = '\0';

            if (manual_strcmp(command, "START") == 0) {
                // Masuk ke Login Menu
                // int loginMenuActive = 1;
                while (1) {
                    LoginMenu();
                    STARTWORD();
                    WordToString(currentWord, convertwsmm);
                    for (int i = 0; i < currentWord.Length; i++) {
                        command[i] = convertwsmm[i];
                    }
                    command[currentWord.Length] = '\0';
                    printf("\n");

                    if (manual_strcmp(command, "LOGIN") == 0) {
                        printf("Masukkan username: ");
                        STARTWORD();
                        char username[MAX_LENGTH];
                        WordToString(currentWord, username);

                        printf("Masukkan password: ");
                        STARTWORD();
                        char password[MAX_LENGTH];
                        WordToString(currentWord, password);

                        loginUser(&system, username, password, &isLoggedIn);
                        if(isLoggedIn) break;

                    } else if (manual_strcmp(command, "REGISTER") == 0) {
                        char username[MAX_LENGTH];
                        printf("Masukkan username: ");
                        STARTWORD();
                        WordToString(currentWord, username);

                        char password[MAX_LENGTH];
                        printf("Masukkan password: ");
                        STARTWORD();
                        WordToString(currentWord, password);

                        registerUser(&system, username, password);
                    } else if (manual_strcmp(command, "HELP") == 0) {
                        helpinlogin();
                    } else if (manual_strcmp(command, "QUIT") == 0) {
                        printf("\nExiting program...\n");
                        return 0;
                    } else {
                        printf("\nCommand tidak dikenali. Gunakan REGISTER, LOGIN, atau EXIT.\n");
                    }
                }
            } else if (manual_strcmp(command, "LOAD") == 0) {
                printf("\nLoad feature is under development.\n");
            } else if (manual_strcmp(command, "HELP") == 0) {
                helpinwelcome();
            } else if (manual_strcmp(command, "QUIT") == 0) {
                printf("\nExiting program...\n");
                running = 0;
            } else {
                printf("\nInvalid command. Please try again.\n");
            }
        } else {
            // Menampilkan Main Menu setelah Login
            MainMenu();
            STARTSENTENCE();
            WordToString(currentWord, convertwsmm);

            for (int i = 0; i < currentWord.Length; i++) {
                command[i] = convertwsmm[i];
            }
            command[currentWord.Length] = '\0';
            printf("\n");

            if (manual_strcmp(command, "HELP") == 0) {
                helpinmain();
            } else if (manual_strcmp(command, "QUIT") == 0) {
                printf("\nExiting program...\n");
                running = 0;
            } else if (manual_strcmp(command, "WORK") == 0) {
                work(&uang_asal);
            } else if (manual_strcmp(command, "WORK CHALLENGE") == 0) {
                workChallenge(&uang_asal);
            } else if (manual_strcmp(command, "LOGOUT") == 0){
                logoutUser(&system, &isLoggedIn);
            } else {
                printf("\nInvalid command. Please try again.\n");
            }
        }
    }

    return 0;
}
