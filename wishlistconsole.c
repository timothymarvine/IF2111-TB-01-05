#include "wishlistconsole.h"
#include <stdlib.h>
#include <stdio.h>
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

void wishlistAdd(LinkedList *L) {
    char NamaBarang[100];

    printf("\n>> WISHLIST ADD\n");
    printf("Masukkan nama barang: ");

    STARTSENTENCE();
    WordToString(currentWord, NamaBarang);

    if (!IsBarangValid(NamaBarang)) {
        printf("Tidak ada barang dengan nama %s!\n", NamaBarang);
        return;
    }

    if (Search(*L, NamaBarang) != NIL) {
        printf("%s sudah ada di wishlist!\n", NamaBarang);
    } else {
        Address P = Allocate(NamaBarang);
        if (P != NIL) {
            InsertLastL(L, P);
            printf("Berhasil menambahkan %s ke wishlist!\n", NamaBarang);
        } else {
            printf("Gagal menambahkan %s ke wishlist. Alokasi memori gagal.\n", NamaBarang);
        }
    }
}

void wishlistSwap(LinkedList *L, int i, int j) {
    if (i == j) {
        printf("Gagal menukar posisi, posisi ke-%d dan ke-%d adalah sama.\n", i, j);
        return;
    }

    Address Pi = FirstL(*L), Pj = FirstL(*L);

    for (int index = 1; Pi != NIL && index < i; index++) {
        Pi = NextL(Pi);
    }
    for (int index = 1; Pj != NIL && index < j; index++) {
        Pj = NextL(Pj);
    }

    if (Pi == NIL || Pj == NIL) {
        printf("Gagal menukar posisi! Salah satu indeks tidak valid.\n");
    } else {
        char *temp = InfoL(Pi);
        InfoL(Pi) = InfoL(Pj);
        InfoL(Pj) = temp;

        printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", InfoL(Pi), InfoL(Pj));
    }
}

void wishlistRemoveIndex(LinkedList *L, int index) {
    if (IsListEmpty(*L)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    Address P = FirstL(*L);
    for (int currentIndex = 1; P != NIL && currentIndex < index; currentIndex++) {
        P = NextL(P);
    }

    if (P == NIL) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", index);
    } else {
        printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", index);
        if (P == FirstL(*L)) {
            DeleteFirstL(L, &P);
        } else if (P == LastL(*L)) {
            DeleteLastL(L, &P);
        } else {
            NextL(PrevL(P)) = NextL(P);
            PrevL(NextL(P)) = PrevL(P);
        }
        Deallocate(P);
    }
}

void wishlistRemove(LinkedList *L) {
    char item[100];

    printf("Masukkan nama barang yang akan dihapus: ");
    STARTSENTENCE();
    WordToString(currentWord, item);

    for (Address temp = FirstL(*L); temp != NIL; temp = NextL(temp)) {
        if (MyStrCmp(InfoL(temp), item) == 0) {
            if (temp == FirstL(*L)) {
                DeleteFirstL(L, &temp);
            } else if (temp == LastL(*L)) {
                DeleteLastL(L, &temp);
            } else {
                NextL(PrevL(temp)) = NextL(temp);
                PrevL(NextL(temp)) = PrevL(temp);
            }
            printf("%s berhasil dihapus dari WISHLIST!\n", item);
            Deallocate(temp);
            return;
        }
    }

    printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", item);
}

void wishlistClear(LinkedList *L) {
    Address P;
    while (!IsListEmpty(*L)) {
        DeleteFirstL(L, &P);
        Deallocate(P);
    }
    printf("Wishlist telah dikosongkan.\n");
}

void wishlistShow(LinkedList L) {
    if (IsListEmpty(L)) {
        printf("Wishlist kamu kosong!\n");
    } else {
        printf("Berikut adalah isi wishlist-mu:\n");
        int index = 1;
        for (Address P = FirstL(L); P != NIL; P = NextL(P)) {
            printf("%d. %s\n", index, InfoL(P));
            index++;
        }
    }
}

int main() {
    LinkedList Wishlist;
    CreateList(&Wishlist);

    int choice;
    char convert[50];
    do {
        printf("\n=== Wishlist Management ===\n");
        printf("1. Tambah barang ke wishlist\n");
        printf("2. Tukar posisi barang\n");
        printf("3. Hapus barang berdasarkan indeks\n");
        printf("4. Hapus barang berdasarkan nama\n");
        printf("5. Kosongkan wishlist\n");
        printf("6. Tampilkan wishlist\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        STARTWORD();
        WordToString(currentWord, convert);
        choice = stringToInteger(convert);

        switch (choice) {
            case 1:
                wishlistAdd(&Wishlist);
                break;

            case 2: {
                int i, j;
                printf("Masukkan indeks pertama: ");
                scanf("%d", &i);
                printf("Masukkan indeks kedua: ");
                scanf("%d", &j);
                wishlistSwap(&Wishlist, i, j);
                break;
            }

            case 3: {
                int index;
                printf("Masukkan indeks barang yang ingin dihapus: ");
                scanf("%d", &index);
                wishlistRemoveIndex(&Wishlist, index);
                break;
            }

            case 4:
                wishlistRemove(&Wishlist);
                break;

            case 5:
                wishlistClear(&Wishlist);
                break;

            case 6:
                wishlistShow(Wishlist);
                break;

            case 0:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (choice != 0);

    wishlistClear(&Wishlist); // Pastikan memori dibebaskan
    return 0;
}
