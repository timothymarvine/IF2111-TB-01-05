#include <stdio.h>
#include <stdlib.h>
#include "mesin_karakter.h"
#include "mesin_karakter.c"
#include "mesin_kata.h"
#include "mesin_kata.c"

int main() {
    printf("Masukkan Kalimat: ");STARTSENTENCE(); printf("\n");
    /*ingoreblank, advword, sama copt word udah disini*/
    PrintKata(currentWord);
    char *string = (char*) malloc (sizeof(char) * 100);
    WordToString(currentWord, string); printf("\n");
    printf("Panjang kalimat mu: %d\n", Strlen(string));
    printf("Masukkan Kata 1: "); STARTWORD(); printf("\n");
    /*ingoreblank, advword, sama copt word udah disini*/
    PrintKata(currentWord);
    WordCompareString(currentWord, string);
    return 0;
}