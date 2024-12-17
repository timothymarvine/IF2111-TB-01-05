#include <stdio.h>
#include "ADT\mesinkata\mesinkata.h"
#include "boolean.h"
#include "load.h"

void LOAD(char command2[], Barang barang[], int *jumlahBarang, User user[], int *jumlahUser) {
    int i, N, M;
    char filename[100] = "src/save/";

    for (i = 0; i < Strlen(command2); i++) {
        filename[9 + i] = command2[i];
    }
    filename[9 + Strlen(command2)] = '\0';

    STARTWORDFILE(filename);

    if (EndWord) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }

    N = WordToInt(currentWord);
    *jumlahBarang = N;

    for (i = 0; i < N; i++) {
        ADVWORD();
        barang[i].price = WordToInt(currentWord);

        ADVSENTENCE();
        WordToCharArray(currentWord, barang[i].name);
    }

    ADVWORD();
    M = WordToInt(currentWord);
    *jumlahUser = M;

    for (i = 0; i < M; i++) {
        ADVWORD();
        user[i].uang = WordToInt(currentWord);

        ADVWORD();
        WordToCharArray(currentWord, user[i].namaUser);

        ADVWORD();
        WordToCharArray(currentWord, user[i].password);
    }

    if(strCmpr(command2, "config.txt")){
        printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.");
    } else {
        printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
    }
}

// int main() {
//     Barang daftarBarang[100];
//     User daftarUser[100];
//     int jumlahBarang, jumlahUser;
//     Word filename;

//     char *namaFile = "savefile.txt";
//     for (int i = 0; namaFile[i] != '\0'; i++) {
//         filename.TabWord[i] = namaFile[i];
//         filename.Length = i + 1;
//     }

//     LOAD(filename, daftarBarang, &jumlahBarang, daftarUser, &jumlahUser);

//     printf("Jumlah Barang: %d\n", jumlahBarang);
//     for (int i = 0; i < jumlahBarang; i++) {
//         printf("Barang %d: %s, Harga: %d\n", i + 1, daftarBarang[i].namaBarang, daftarBarang[i].harga);
//     }

//     printf("Jumlah User: %d\n", jumlahUser);
//     for (int i = 0; i < jumlahUser; i++) {
//         printf("User %d: %s, Uang: %d, Password: %s\n", i + 1, daftarUser[i].namaUser, daftarUser[i].uang, daftarUser[i].password);
//     }

//     return 0;
// }
