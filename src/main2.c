#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include "menu.h"

int main(){
    char perintah[100], gandengan[100], dir[100], barang[100], activeUser[50];
    int angka, totalUser, uang, result = 0, loaded = 0, welcoming = 1, loggingIn = 0, loggedIn = 0, centralIndex;
    Queue q; ArrayDin item = MakeArrayDin(); UserCheckOut central[10];
    CreateEmptyQ(&q);
    System auth; initializeSystem(&auth);

    while(1){
        if(welcoming == 1){
            WelcomeMenu();
            STARTSENTENCE();
            currentWord.TabWord[currentWord.Length] = '\0';
            int wordIdx = 0;
            oneWordCmd(currentWord, perintah, &wordIdx);
            
            if(strCmpr(perintah, "START")){
                ConfigReader(central, &totalUser, &item, &loaded);
                if(loaded){
                    loggingIn = 1;
                    welcoming = 0;
                }
            } else if(strCmpr(perintah, "LOAD")){
                dirReader(currentWord, dir, &wordIdx);
                LOAD(dir, central, &item, &totalUser, &loaded);
                if(loaded){
                    loggingIn = 1;
                    welcoming = 0;
                }
            } else if(strCmpr(perintah, "HELP")){
                helpinwelcome();
            } else if(strCmpr(perintah, "QUIT")){
                printf("Exiting program...");
                delay(2);
                break;
            } else {
                printf("Command tidak dikenal. Masukkan perintah yang benar.");
            }
        } else if(loggingIn == 1){
            int wordIdx = 0;
            LoginMenu();
            STARTSENTENCE();
            currentWord.TabWord[currentWord.Length] = '\0';
            oneWordCmd(currentWord, perintah, &wordIdx);

            if(strCmpr(perintah, "LOGIN")){
                printf("Masukkan username: ");
                STARTWORD();
                char  username[50];
                WordToString(currentWord, username);

                printf("Masukkan password: ");
                STARTWORD();
                char password[50];
                WordToString(currentWord, password);

                loginUser(central, username, password, &loggedIn, totalUser, activeUser);
                if(loggedIn){
                    int i = 0;
                    while(i < totalUser){
                        if(strCmpr(username, central[i].name)){
                            break;
                        }
                        i++;
                    }
                    centralIndex = i;
                    uang = central[i].money;
                    loggingIn = 0;
                }
            } else if(perintah, "REGISTER"){
                printf("Masukkan username: ");
                STARTWORD();
                char  username[50];
                WordToString(currentWord, username);

                printf("Masukkan password: ");
                STARTWORD();
                char password[50];
                WordToString(currentWord, password);

                registerUser(central, username, password, &totalUser);
            } else if(strCmpr(perintah, "HELP")){
                helpinlogin();
            } else if(strCmpr(perintah, "QUIT")){
                printf("Exiting program...");
                delay(2);
                break;
            } else {
                printf("Command tidak dikenal. Masukkan perintah yang benar.");
            }
        } else if(loggedIn == 1){
            int wordIdx = 0;
            MainMenu();
            STARTSENTENCE();
            currentWord.TabWord[currentWord.Length] = '\0';
            oneWordCmd(currentWord, perintah, &wordIdx);

            if(strCmpr(perintah, "STORE")){
                twoWordCmd(currentWord, gandengan, &wordIdx);

                if(strCmpr(gandengan, "REQUEST")){
                    Request(&q, &item);
                } else if(strCmpr(gandengan, "SUPPLY")){
                    Supply(&q, &item);
                } else if(strCmpr(gandengan, "LIST")){
                    STORELIST(item);
                } else if(strCmpr(gandengan, "REMOVE")){
                    STOREREMOVE(&item);
                }
            } else if(strCmpr(perintah, "WORK")){
                twoWordCmd(currentWord, gandengan, &wordIdx);
                if(gandengan[0] == '\0' || gandengan[0] == '\n' || gandengan[0] == ' '){
                    work(&uang);
                } else if(strCmpr(gandengan, "CHALLENGE")){
                    workChallenge(&uang);
                }
            } else if(strCmpr(perintah, "CART")){
                twoWordCmd(currentWord, gandengan, &wordIdx);

                if(strCmpr(gandengan, "ADD")){
                    itemReader(currentWord, barang, &wordIdx);
                    numReader(currentWord, &result, &wordIdx);

                    CartAdd(&central[centralIndex].cart, result, item, barang);
                } else if(strCmpr(gandengan, "REMOVE")){
                    itemReader(currentWord, barang, &wordIdx);
                    numReader(currentWord, &result, &wordIdx);

                    CartRemove(&central[centralIndex].cart, -result, barang);
                } else if(strCmpr(gandengan, "SHOW")){
                    CARTSHOW(central[centralIndex].cart, item);
                } else  if(strCmpr(gandengan, "PAY")){
                    CARTPAY(&central[centralIndex].cart, item, &central[centralIndex].history, &uang);
                }
            } else if(strCmpr(perintah, "WISHLIST")){
                twoWordCmd(currentWord, gandengan, &wordIdx);

                if(strCmpr(gandengan, "ADD")){
                    wishlistAdd(&central[centralIndex].wishlist);
                } else if(strCmpr(gandengan, "REMOVE")){
                    numReader(currentWord, &result, &wordIdx);

                    if(result != 0){
                        wishlistRemoveIndex(&central[centralIndex].wishlist, result);
                    } else {
                        wishlistRemove(&central[centralIndex].wishlist);
                    }
                } else if(strCmpr(gandengan, "SWAP")){
                    int a, b;
                    numReader(currentWord, &a, &wordIdx);
                    numReader(currentWord, &b, &wordIdx);

                    wishlistSwap(&central[centralIndex].wishlist, a, b);
                } else if(strCmpr(gandengan, "SHOW")){
                    wishlistShow(central[centralIndex].wishlist);
                } else if(strCmpr(gandengan, "CLEAR")){
                    wishlistClear(&central[centralIndex].wishlist);
                }
            } else if(strCmpr(perintah, "HISTORY")){
                numReader(currentWord, &result, &wordIdx);

                ShowHistory(&central[centralIndex].history, result);
            } else if(strCmpr(perintah, "PROFILE")){
                showProfile(activeUser, uang);
            } else if(strCmpr(perintah, "HELP")){
                helpinmain();
            } else if(strCmpr(perintah, "LOGOUT")){
                logoutUser(activeUser, &loggedIn);
                loggingIn = 1;
            } else if(strCmpr(perintah, "SAVE")){
                dirReader(currentWord, dir, &wordIdx);

                SAVE(dir, central, item, totalUser);
            } else if(strCmpr(perintah, "QUIT")){
                printf("\nTerima kasih telah berbelanja di PURRMART!\n");
                printf("\n\nExiting program...");
                delay(3);

                break;
            } else {
                printf("Command tidak dikenal. Masukkan perintah yang benar.");
            }
        }
    }
}