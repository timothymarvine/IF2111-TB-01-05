#include <stdio.h>
#include "workChallenge.h"
#include "tebakangka.h"
#include "ADT\mesinkata\mesinkata.h"
#include "ADT\mesinkarakter\mesinkarakter.h"

void W0RDL399(){
    printf("Lagi proses");
}

void workChallenge(int *uang_asal){
        if (*uang_asal <= 0) {
        printf("Uang anda tidak cukup untuk memulai challenge! Silakan bekerja terlebih dahulu pada menu work.\n");
        return;
        }

    int pilihanchallenge;
    char apapun;
    printf("Daftar challenge yang tersedia: \n");
    printf("1. Tebak Angka (biaya main=200)\n");
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("Masukkan challenge yang hendak dimainkan: ");
    STARTWORD();
    WordToString(currentWord, &apapun);
    pilihanchallenge = stringToInteger(&apapun);
    printf("\n");

    switch (pilihanchallenge){
        case 1:
            tebakAngka(uang_asal);
            break;
        case 2:
            W0RDL399();
            break;
        default:
            printf("Pilihanmu tidak ada!");
            break;
    }
}