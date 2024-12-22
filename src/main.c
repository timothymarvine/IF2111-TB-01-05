#include "ADT\array\array.h"
#include "ADT\array\arraydin.h"
#include "ADT\kustom\datatype.h"
#include "ADT\kustom\mainadt.h"
#include "ADT\map\map.h"
#include "ADT\mesinkata\mesinkata.h"
#include "ADT\queue\queue.h"
#include "ADT\definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include "menu.h"

int main() {
    char convertwsmm[50], command[30], kesempatan, filename[MAX_LEN];
    int isLoggedIn = 0, running = 1, uang_asal = 0, barangCtr = 0, userCtr = 0, saved = 1;
    System system;
    UserCheckOut central[10];
    initializeSystem(&system);
    Queue q; CreateEmptyQ(&q);
    ArrayDin list = MakeArrayDin();
    User data[MAX_USERS];
    Barang stokItem[MAX_LEN];

    while (running) {
        char perintah[100], barang[100]; int angka;
        if (!isLoggedIn) {
            // Menampilkan Welcome Menu
            WelcomeMenu();
            STARTSENTENCE();
            WordToString(currentWord, convertwsmm); // Menggunakan array char untuk string

            for (int i = 0; i < currentWord.Length; i++) {
                command[i] = convertwsmm[i];
            }
            command[currentWord.Length] = '\0';

            if (manual_strcmp(command, "START") == 0) {
                LOAD("config.txt", stokItem, &barangCtr, &userCtr, central);
                for(int i = 0; i < 1; i++){
                    strCopy(system.users[i].username, central[i].name);
                    strCopy(system.users[i].password, central[i].password);
                    system.totalUsers++;
                    strCopy(list.A[i].name, stokItem[i].name);
                    list.A[i].price = stokItem[i].price;
                    list.Neff++; 
                }
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

                        loginUser(&system, username, password, &isLoggedIn, central);
                        int i = 0;
                        while(1){
                            if(strCmpr(username, central[i].name)){
                                break;
                            }
                            i++;
                        }
                        if(isLoggedIn) {
                            uang_asal = central[i].money;
                            break;
                        }

                    } else if (manual_strcmp(command, "REGISTER") == 0) {
                        char username[MAX_LENGTH];
                        printf("Masukkan username: ");
                        STARTWORD();
                        WordToString(currentWord, username);

                        char password[MAX_LENGTH];
                        printf("Masukkan password: ");
                        STARTWORD();
                        WordToString(currentWord, password);

                        registerUser(&system, username, password, central);
                        userCtr = system.totalUsers; saved = 0;
                    } else if (manual_strcmp(command, "HELP") == 0) {
                        helpinlogin();
                    } else if (manual_strcmp(command, "QUIT") == 0) {
                        if(saved == 0){
                            printf("Apakah anda ingin menyimpan data sesi sekarang (Y/N)? ");
                            STARTWORD();
                            if(currentWord.TabWord[0] == 'N'){
                                running = 0;
                            } else if (currentWord.TabWord[0] == 'Y'){
                                Barang *itemData = malloc(barangCtr * sizeof(Barang));
                                int x = 0;
                                while(x < barangCtr){
                                    strCopy(itemData[x].name, list.A[x].name);
                                    itemData[x].price = list.A[x].price;
                                    x++;
                                }
                                printf("Ketik \'SAVE\' diikuti nama file: ");
                                STARTSENTENCE();
                                Word fname; fname.Length = currentWord.Length;
                                WordToString(currentWord, fname.TabWord);
                                SaveInterpreter(command, &fname);
                                SAVE(fname, itemData, barangCtr, userCtr, central);
                                free(itemData);
                                running = 0;
                            }
                            printf("\nExiting program...\n");
                            delay(3);
                            return 0;
                        } else {
                            printf("\nExiting program...\n");
                            delay(3);
                            return 0;
                        }
                    } else {
                        printf("\nCommand tidak dikenali. Gunakan REGISTER, LOGIN, atau EXIT.\n");
                    }
                }
            } else if (manual_strcmp(command, "LOAD") == 0) {
                Word filedir;
                SaveInterpreter(command, &filedir);
                LOAD(filedir.TabWord, stokItem, &barangCtr, &userCtr, central);
                for(int i = 0; i < userCtr; i++){
                    strCopy(system.users[i].username, data[i].namaUser);
                    strCopy(system.users[i].password, data[i].password);
                    system.totalUsers++;
                }
                for(int i = 0; i < barangCtr; i++){
                    strCopy(list.A[i].name, stokItem[i].name);
                    list.A[i].price = stokItem[i].price;
                    list.Neff++;
                }
            } else if (manual_strcmp(command, "HELP") == 0) {
                helpinwelcome();
            } else if (manual_strcmp(command, "QUIT") == 0) {
                if(saved == 0){
                    printf("Apakah anda ingin menyimpan data sesi sekarang (Y/N)? ");
                    STARTWORD();
                    if(currentWord.TabWord[0] == 'N'){
                        running = 0;
                    } else if (currentWord.TabWord[0] == 'Y'){
                        Barang *itemData = malloc(barangCtr * sizeof(Barang));
                        int x = 0;
                        while(x < barangCtr){
                            strCopy(itemData[x].name, list.A[x].name);
                            itemData[x].price = list.A[x].price;
                            x++;
                        }
                        printf("Ketik \'SAVE\' diikuti nama file: ");
                        STARTSENTENCE();
                        Word fname; fname.Length = currentWord.Length;
                        WordToString(currentWord, fname.TabWord);
                        SaveInterpreter(command, &fname);
                        SAVE(fname, itemData, barangCtr, userCtr, central);
                        free(itemData);
                        running = 0;
                    }
                    printf("\nExiting program...\n");
                    delay(3);
                    return 0;
                } else {
                    printf("\nExiting program...\n");
                    delay(3);
                    return 0;
                }
            } else {
                printf("\nInvalid command. Please try again.\n");
            }
        } else {
            int indexCentral = 0;
            while(1){
                if(strCmpr(system.activeUser, central[indexCentral].name)){
                    break;
                }
                indexCentral++;
            }
            uang_asal = central[indexCentral].money;
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
                if(saved == 0){
                    printf("Apakah anda ingin menyimpan data sesi sekarang (Y/N)? ");
                    STARTWORD();
                    if(currentWord.TabWord[0] == 'N'){
                        printf("\nExiting program...\n");
                        delay(3);
                        running = 0;
                    } else if (currentWord.TabWord[0] == 'Y'){
                        Barang *itemData = malloc(barangCtr * sizeof(Barang));
                        int x = 0;
                        while(x < barangCtr){
                            strCopy(itemData[x].name, list.A[x].name);
                            itemData[x].price = list.A[x].price;
                            x++;
                        }
                        printf("Ketik \'SAVE\' diikuti nama file: ");
                        STARTSENTENCE();
                        Word fname;
                        fname.Length = 0;
                        SaveInterpreter(command, &fname);
                        SAVE(fname, itemData, barangCtr, userCtr, central);
                        free(itemData);
                        delay(3);
                        running = 0;
                    }
                } else {
                    printf("\nExiting program...\n");
                    delay(3);
                    running = 0;
                }
            } else if (manual_strcmp(command, "WORK") == 0) {
                work(&uang_asal);
                Word username;
                strCopy(username.TabWord, system.activeUser);
                for(int i = 0; i < userCtr; i++){
                    if(WordCompareString(username, central[indexCentral].name)){
                        central[indexCentral].money = uang_asal;
                    }
                }
                saved = 0;
            } else if(manual_strcmp(command, "WORK CHALLENGE") == 0){
                workChallenge(&uang_asal);
                Word username;
                strCopy(username.TabWord, system.activeUser);
                for(int i = 0; i < userCtr; i++){
                    if(WordCompareString(username, central[indexCentral].name)){
                        central[indexCentral].money = uang_asal;
                    }
                }
                saved = 0;
            } else if (manual_strcmp(command, "LOGOUT") == 0){
                logoutUser(&system, &isLoggedIn);
            } else if (manual_strcmp(command, "STORE REQUEST") == 0){
                Request(&q, &list);
            } else if(manual_strcmp(command, "STORE SUPPLY") == 0){
                Supply(&q, &list);
                barangCtr = list.Neff; saved = 0;
            } else if(manual_strcmp(command, "STORE LIST") == 0){
                STORELIST(list);
            } else if(manual_strcmp(command, "STORE REMOVE") == 0){
                STOREREMOVE(&list); saved = 0;
            } else if (isSave(command)){
                Barang *itemData = malloc(barangCtr * sizeof(Barang));
                int x = 0;
                while(x < barangCtr){
                    strCopy(itemData[x].name, list.A[x].name);
                    itemData[x].price = list.A[x].price;
                }
                Word fname; fname.Length = 0;
                SaveInterpreter(command, &fname);
                SAVE(fname, itemData, barangCtr, userCtr, central);
                saved = 1;
                free(itemData);
            } else if(isCart(currentWord) != 0){
                if(isCart(currentWord) == 1){
                    int i = 9, num, j = 0; Word x; char angka[6];
                    x.Length = 0;
                    while(currentWord.TabWord[i] < '0' || currentWord.TabWord[i] > '9'){
                        x.TabWord[j] = currentWord.TabWord[i];
                        j++; i++; x.Length++;
                    }
                    x.TabWord[j - 1] = '\0'; x.Length -= 1;
                    j = 0;
                    while(currentWord.TabWord[i] != '\n'){
                        angka[j] = currentWord.TabWord[i];
                        j++; i++;
                    }
                    num = stringToInteger(angka);

                    CartAdd(&central[indexCentral].cart, num, list, x);
                } else if(isCart(currentWord) == 2){
                    int i = 9, num, j = 0; Word x; char angka[6];
                    x.Length = 0;
                    while(currentWord.TabWord[i] < '0' || currentWord.TabWord[i] > '9'){
                        x.TabWord[j] = currentWord.TabWord[i];
                        j++; i++; x.Length++;
                    }
                    x.TabWord[j - 1] = '\0'; x.Length -= 1;
                    j = 0;
                    while(currentWord.TabWord[i] != '\n'){
                        angka[j] = currentWord.TabWord[i];
                        j++; i++;
                    }
                    num = stringToInteger(angka);

                    CartRemove(&central[indexCentral].cart, -num, x);
                } else if(isCart(currentWord) == 3){
                    CARTSHOW(central[indexCentral].cart, list);
                } else if(isCart(currentWord) == 4){
                    CARTPAY(&central[indexCentral].cart, list, &central[indexCentral].history, &uang_asal);
                }
            } else if(isHistory(currentWord) != 0){
                int i = 8, j = 0; char angka[6];
                while(currentWord.TabWord[i] != '\n'){
                    angka[j] = currentWord.TabWord[i];
                    i++; j++;
                }
                int num = stringToInteger(angka);
                ShowHistory(&central[indexCentral].history, num);
            } else if(isWl(currentWord) != 0){
                if(isWl(currentWord) == 1){
                    wishlistAdd(&central[indexCentral].wishlist);
                } else if(isWl(currentWord) == 2){
                    char angka[6]; int i = 14, j = 0;
                    while(currentWord.TabWord[i] != ' '){
                        angka[j] = currentWord.TabWord[i];
                        j++; i++;
                    }
                    angka[j] = '\0';
                    int a = stringToInteger(angka);
                    j = 0; i++;
                    while(currentWord.TabWord[i] != ' '){
                        angka[j] = currentWord.TabWord[i];
                        j++; i++;
                    }
                    int b = stringToInteger(angka);

                    wishlistSwap(&central[indexCentral].wishlist, a, b);
                } else if(isWl(currentWord) == 3){
                    int i = 16, j = 0, num; char angka[6];
                    if(currentWord.TabWord[15] == '\n' || currentWord.TabWord[15] == '\0'){
                        wishlistRemove(&central[indexCentral].wishlist);
                    } else {
                        while(currentWord.TabWord[i] != '\n' && currentWord.TabWord[i] != '\0'){
                            angka[j] = currentWord.TabWord[i];
                            j++; i++;
                        }
                        num = stringToInteger(angka);

                        wishlistRemoveIndex(&central[indexCentral].wishlist, num);
                    }
                } else if(isWl(currentWord) == 4){
                    wishlistClear(&central[indexCentral].wishlist);
                } else if(isWl(currentWord) == 5){
                    wishlistShow(central[indexCentral].wishlist);
                }
            } else if(manual_strcmp(command, "PROFILE") == 0) {
                showProfile(&system, central, system.totalUsers, uang_asal);
            } else {
                printf("\nInvalid command. Please try again.\n");
            }
        }
    }

    return 0;
}
