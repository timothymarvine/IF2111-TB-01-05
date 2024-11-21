#include <stdio.h>
#include "workChallenge.h"
#include "tebakangka.h"

void W0RDL399(){
    printf("Lagi proses");
}

void workChallenge(int *uang_asal){
    int pilihanchallenge;
    printf("Daftar challenge yang tersedia: \n");
    printf("1. Tebak Angka (biaya main=200)\n");
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("Masukkan challenge yang hendak dimainkan: ");
    scanf("%d", &pilihanchallenge);
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