#include "mesinkata.h"
#include <stdio.h>

int main(){
    char satu[100], dua[100], tiga[100];
    int angka = 0, nomor = 0, index = 0;

    printf("Coba ketik: ");
    STARTSENTENCE();

    oneWordCmd(currentWord, satu, &index);
    twoWordCmd(currentWord, dua, &index);

    printf("%s\n", satu);
    printf("%s\n", dua);

    printf("Coba kalo angka: ");
    STARTSENTENCE();
    index = 0;

    numReader(currentWord, &angka, &index);
    numReader(currentWord, &nomor, &index);

    printf("%d %d\n", angka, nomor);
}