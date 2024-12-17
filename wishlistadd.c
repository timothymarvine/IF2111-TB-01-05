#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

int MyStrLen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void MyStrCpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int MyStrCmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

const char *DatabaseBarang[] = {
    "Ayam Geprek Bakar Crispy Besthal",
    "Ayam Geprek Sambalado Besthal"
};
const int TotalBarang = 2;

int IsBarangValid(const char *NamaBarang) {
    for (int i = 0; i < TotalBarang; i++) {
        if (MyStrCmp(DatabaseBarang[i], NamaBarang) == 0) {
            return 1; // Barang valid
        }
    }
    return 0; // Barang tidak valid
}

int main() {
    LinkedList Wishlist;
    CreateList(&Wishlist);
    char NamaBarang[100];

        printf("\n>> WISHLIST ADD\n");
        printf("Masukkan nama barang: ");
        
        // Membaca input menggunakan mesin kata
        STARTSENTENCE();
        WordToString(currentWord, NamaBarang);

        // Validasi jika nama barang ada di database
        if (!IsBarangValid(NamaBarang)) {
            printf("Tidak ada barang dengan nama %s!\n", NamaBarang);
        }

        // Cari apakah barang sudah ada di wishlist
        if (Search(Wishlist, NamaBarang) != NIL) {
            printf("%s sudah ada di wishlist!\n", NamaBarang);
        } else {
            // Tambahkan ke wishlist
            Address P = Allocate(NamaBarang);
            if (P != NIL) {
                InsertLastL(&Wishlist, P);
                printf("Berhasil menambahkan %s ke wishlist!\n", NamaBarang);
            } else {
                printf("Gagal menambahkan %s ke wishlist. Alokasi memori gagal.\n", NamaBarang);
            }
        }

    return 0;
}
