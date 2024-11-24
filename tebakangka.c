#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "tebakangka.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "menu.h"

int generateRandomNumber(int min, int max) {
    time_t t;
    t = time(NULL);

    unsigned int seed = (unsigned int)t;
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;

    int randomNum = (seed % (max - min + 1)) + min;
    return randomNum;
}

void tebakAngka(int *uang_asal){
    int biaya_main = 200, tebakAngka, RNGnumber, hadiah = 500, hadiah_sisa_uang;
    int kesempatan = 10;
    char convert;
    boolean tebakanBenar = false;
    if (*uang_asal < biaya_main){
        printf("Uang Anda tidak cukup!");
        return;
    }

    *uang_asal -= biaya_main;
    printf("Uang Anda tersisa %d.\n\n", *uang_asal);

    printf("Tebak Angka (1-100) dengan kesempatan tersisa %d.\n", kesempatan);

    RNGnumber = generateRandomNumber(1,100);

    while(kesempatan > 0 && tebakanBenar == false){
        printf("Tebak Angka = ");
        STARTWORD();
        WordToString(currentWord, &convert);
        tebakAngka = stringToInteger(&convert);
        if (tebakAngka < RNGnumber){
            printf("Tebakanmu lebih kecil!\n");
        }else if(tebakAngka > RNGnumber){
            printf("Tebakanmu lebih besar!\n");
        }else if(tebakAngka == RNGnumber){
            tebakanBenar = true;
            if(kesempatan == 10){
                hadiah_sisa_uang = 550;
                printf("Tebakanmu benar! %d rupiah telah ditambahkan ke akun Anda\n",hadiah_sisa_uang);
                *uang_asal += hadiah_sisa_uang;
                printf("Uang anda sekarang adalah = %d.\n", *uang_asal);
                return;
            }else{
                hadiah_sisa_uang = 550 - 50*(10-kesempatan);
                printf("Tebakanmu benar! %d rupiah telah ditambahkan ke akun Anda\n",hadiah_sisa_uang);
                *uang_asal += hadiah_sisa_uang;
                printf("Uang anda sekarang adalah = %d.\n", *uang_asal);
                return;
            }
        }
    kesempatan--;
    printf("Sisa kesempatan adalah %d.\n\n", kesempatan);
    }
    hadiah_sisa_uang = 550 - 50*(10-kesempatan);
    printf("Kesempatan Anda sudah habis. Angka yang benar adalah %d. Uang Anda tersisa %d\n", RNGnumber, hadiah_sisa_uang);
    
}