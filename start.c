// #include "mesinkata.h"
#include <stdio.h>

int main(void){
    static FILE *config;

    int item_ctr, user_ctr;
    config = fopen("config.txt", "r");
    if(config == NULL){
        printf("File tidak ditemukan.\n");
        return 1;
    }

    char user[50];
    char password[50];
    char barang[50];
    int harga;
    int uang;

    fscanf(config, "%d", &item_ctr) == 1;

    for(int i = 0; i < item_ctr; i++){
        fscanf(config, "%d %[^\n]", &harga, barang);
        printf("Barang: %s\n", barang);
        printf("Harga: %d\n", harga);
    }

    fscanf(config, "%d", &user_ctr) == 1;

    for(int i = 0; i < user_ctr; i++){
        fscanf(config, "%d %s %s", &uang, user, password) == 3;
        printf("User: %s\n", user);
        printf("Pass: %s\n", password);
        printf("Uang: %d\n", uang);
    }

    fclose(config);
    return 0;
}