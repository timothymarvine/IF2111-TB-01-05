#include <stdio.h>
#include "workChallenge.h"
int main(){
    int uang_asal = 5000;
    char kesempatan;

    workChallenge(&uang_asal);

    char pilihanyesorno = 'Y';

    while (pilihanyesorno != 'N'){
        printf("Apakah anda masih mau bermain? (Y/N)\n");
        scanf(" %c", &pilihanyesorno);
        if (pilihanyesorno == 'Y'){
            workChallenge(&uang_asal);
        }else{
            printf("Terima kasih sudah bermain Tebak Angka!");
        }
    }
    return 0;
}