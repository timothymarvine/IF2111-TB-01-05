#include <stdio.h>
#include "menu.h"
#include "workChallenge.h"
int main() {
    char command[10];
    int isLoggedIn = 0; // Status login pengguna (0 = tidak login, 1 = login)
    int running = 1;    // Status jalannya program (0 = berhenti, 1 = berjalan)
    int uang_asal = 5000;
    char kesempatan;

    while (running) {
        if (!isLoggedIn) {
            // Menampilkan Welcome Menu
            WelcomeMenu();
            scanf("%s", command);

            if (manual_strcmp(command, "START") == 0) {
                // Masuk ke Login Menu
                int loginMenuActive = 1;
                while (loginMenuActive) {
                    LoginMenu();
                    scanf("%s", command);
                    printf("\n");

                    if (manual_strcmp(command, "LOGIN") == 0) {
                        printf("\nLogin successful!\n");
                        isLoggedIn = 1;
                        loginMenuActive = 0;
                    } else if (manual_strcmp(command, "REGISTER") == 0) {
                        printf("\nRegistration successful! Now you can login.\n");
                    } else if (manual_strcmp(command, "HELP") == 0) {
                        helpinlogin();
                    } else if (manual_strcmp(command, "QUIT") == 0) {
                        printf("\nExiting program...\n");
                        return 0;
                    } else {
                        printf("\nInvalid command. Please try again.\n");
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
            scanf("%s", command);
            printf("\n");

            if(manual_strcmp(command, "HELP") == 0){
                helpinmain();
            }else if (manual_strcmp(command, "QUIT") == 0) {
                printf("\nExiting program...\n");
                running = 0;
            }else if (manual_strcmp(command, "WORKCHALLENGE") == 0){
                workChallenge(&uang_asal);
            }else {
                printf("\nInvalid command. Please try again.\n");
            }
        }
    }

    return 0;
}
