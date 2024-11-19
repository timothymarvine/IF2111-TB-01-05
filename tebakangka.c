#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void W0RDL399(){

}

void tebakAngka(int *uang_asal){
    int biaya_main = 200, tebakAngka, RNGnumber, hadiah = 500, kesempatan = 10, hadiah_sisa_uang;
    if (*uang_asal < biaya_main){
        printf("Uang Anda tidak cukup!");
    }

    *uang_asal -= biaya_main;
    printf("Uang Anda tersisa %d.\n", *uang_asal);

    printf("Tebak Angka (1-100) dengan kesempatan tersisa %d \n", kesempatan);

    RNGnumber = generateRandomNumber(1,100);

    while(kesempatan > 0){
        printf("Tebak Angka = ");
        scanf("%d", &tebakAngka);
        if (tebakAngka < RNGnumber){
            printf("Tebakanmu lebih kecil!\n");
        }else if(tebakAngka > RNGnumber){
            printf("Tebakanmu lebih besar!\n");
        }else if(tebakAngka == RNGnumber){
            printf("Tebakanmu benar! %d rupiah telah ditambahkan ke akun Anda\n",hadiah_sisa_uang);
            *uang_asal += hadiah_sisa_uang;
            printf("Uang anda sekarang adalah = %d.", *uang_asal);
            return;
        }
    kesempatan--;
    hadiah_sisa_uang = 550 - 50*(10-kesempatan);
    printf("Sisa kesempatan adalah %d.\n\n", kesempatan);
    }
    printf("Kesempatan Anda sudah habis. Angka yang benar adalah %d. Uang Anda tersisa %d", RNGnumber, *uang_asal);
}

void workChallenge(int *uang_asal){
    int pilihanchallenge;
    printf("Daftar challenge yang tersedia: \n");
    printf("1. Tebak Angka (biaya main=200)\n");
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("Masukkan challenge yang hendak dimainkan: ");
    scanf("%d", &pilihanchallenge);

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

int main(){
    int uang_asal = 5000;
    workChallenge(&uang_asal);
    return 0;
}