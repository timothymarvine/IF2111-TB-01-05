#include <stdio.h>
#include "menu.h"
#include "workChallenge.h"
#include "work.h"
#include "storereq.h"
#include "ADT\mesinkata\mesinkata.h"
#include "ADT\mesinkarakter\mesinkarakter.h"
#include "ADT\array\array.h"
#include "ADT\array\arraydin.h"
#include "rll.h"
#include "save.h"
#include "console.h"
#include "load.h"
#include "WORDL399.h"

int main() {
    char convertwsmm[50], command[10], kesempatan, filename[MAX_LEN];
    int isLoggedIn = 0, running = 1, uang_asal = 0, barangCtr = 0, userCtr = 0, saved = 1;
    System system;
    initializeSystem(&system);
    Queue q; CreateQueue(&q);
    ArrayDin list = MakeArrayDin();
    User data[MAX_USERS];
    array StoreList = Makearray();
    Barang apalah[MAX_LEN];

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
                LOAD("config.txt", apalah, &barangCtr, data, &userCtr);
                for(int i = 0; i < 1; i++){
                    strCopy(system.users[i].username, data[i].namaUser);
                    strCopy(system.users[i].password, data[i].password);
                    system.totalUsers++;
                    strCopy(list.A[i].name, apalah[i].name);
                    strCopy(StoreList.A[i].TabWord, apalah[i].name);
                    list.A[i].price = apalah[i].price;
                    list.Neff++; StoreList.Neff++;
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

                        loginUser(&system, username, password, &isLoggedIn, data);
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

                        registerUser(&system, username, password, data);
                        userCtr = system.totalUsers; saved = 0;
                        // strCopy(data->namaUser, system.users[userCtr - 1].username);
                        // strCopy(data->password, system.users[userCtr - 1].password);
                    } else if (manual_strcmp(command, "HELP") == 0) {
                        helpinlogin();
                    } else if (manual_strcmp(command, "QUIT") == 0) {
                        if(saved == 0){
                            printf("Apakah anda ingin menyimpan data sesi sekarang (Y/N)? ");
                            STARTWORD();
                            if(currentWord.TabWord[0] == 'N'){
                                running = 0;
                            } else if (currentWord.TabWord[0] == 'Y'){
                                Barang itemData[barangCtr];
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
                                SAVE(fname, itemData, barangCtr, data, userCtr);
                                running = 0;
                            }
                            printf("\nExiting program...\n");
                            return 0;
                        }
                    } else {
                        printf("\nCommand tidak dikenali. Gunakan REGISTER, LOGIN, atau EXIT.\n");
                    }
                }
            } else if (manual_strcmp(command, "LOAD") == 0) {
                Word filedir;
                SaveInterpreter(command, &filedir);
                LOAD(filedir.TabWord, apalah, &barangCtr, data, &userCtr);
                for(int i = 0; i < userCtr; i++){
                    strCopy(system.users[i].username, data[i].namaUser);
                    strCopy(system.users[i].password, data[i].password);
                    system.totalUsers++;
                }
                for(int i = 0; i < barangCtr; i++){
                    strCopy(list.A[i].name, apalah[i].name);
                    list.A[i].price = apalah[i].price;
                    list.Neff++;
                }
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
                if(saved == 0){
                    printf("Apakah anda ingin menyimpan data sesi sekarang (Y/N)? ");
                    STARTWORD();
                    if(currentWord.TabWord[0] == 'N'){
                        running = 0;
                    } else if (currentWord.TabWord[0] == 'Y'){
                        Barang itemData[barangCtr];
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
                        // WordToString(currentWord, fname.TabWord);
                        SaveInterpreter(command, &fname);
                        SAVE(fname, itemData, barangCtr, data, userCtr);
                        running = 0;
                    }
                } else {
                    printf("\nExiting program...\n");
                    running = 0;
                }
            } else if (manual_strcmp(command, "WORK") == 0) {
                work(&uang_asal);
                Word username;
                strCopy(username.TabWord, system.activeUser);
                for(int i = 0; i < userCtr; i++){
                    if(WordCompareString(username, data[i].namaUser)){
                        data[i].uang = uang_asal;
                    }
                }
                saved = 0;
            } else if (manual_strcmp(command, "WORK CHALLENGE") == 0) {
                workChallenge(&uang_asal);
                Word username;
                strCopy(username.TabWord, system.activeUser);
                for(int i = 0; i < userCtr; i++){
                    if(WordCompareString(username, data[i].namaUser)){
                        data[i].uang = uang_asal;
                    }
                }
                saved = 0;
            } else if (manual_strcmp(command, "LOGOUT") == 0){
                logoutUser(&system, &isLoggedIn);
            } else if (manual_strcmp(command, "STORE REQUEST") == 0){
                Request(&q, &list);
            } else if (manual_strcmp(command, "STORE SUPPLY") == 0){
                Supply(&q, &list, &StoreList);
                barangCtr = list.Neff; saved = 0;
            } else if (manual_strcmp(command, "STORE LIST") == 0){
                STORELIST(StoreList);
            } else if (manual_strcmp(command, "STORE REMOVE") == 0){
                STOREREMOVE(&StoreList, &list); saved = 0;
            } else if (isSave(command)){
                Barang itemData[barangCtr];
                int x = 0;
                while(x < barangCtr){
                    strCopy(itemData[x].name, list.A[x].name);
                    itemData[x].price = list.A[x].price;
                }
                Word fname; fname.Length = 0;
                SaveInterpreter(command, &fname);
                SAVE(fname, itemData, barangCtr, data, userCtr);
                saved = 1;
            } else {
                printf("\nInvalid command. Please try again.\n");
            }
        }
    }

    return 0;
}
