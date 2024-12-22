
#include <stdio.h>
#include "stack.h"
#include "..\mesinkata\mesinkata.h"

// Fungsi manual untuk menyalin string
void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Menambahkan karakter null-terminator
}

// Fungsi manual untuk menghitung panjang string
int my_strlen(const char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    // Deklarasi stack
    Stack s;
    CreateStack(&s); // Inisialisasi stack kosong

    // Deklarasi variabel untuk elemen stack
    Purchase temp;
    int n;
    char convert[50];

    // Input jumlah elemen yang akan di-push
    printf("Berapa banyak item yang ingin Anda tambahkan ke stack? ");
    STARTWORD();
    WordToString(currentWord, convert);
    n = stringToInteger(convert);

    // Input elemen-elemen stack
    for (int i = 0; i < n; i++) {
        printf("Masukkan nama item %d: ", i + 1);
        STARTWORD(); // Menggunakan mesin kata untuk membaca input
        WordToString(currentWord, convert); // Konversi word ke string
        my_strcpy(temp.itemName, convert);  // Salin ke temp.itemName

        // Push elemen ke stack
        push(&s, temp);
    }

    // Tampilkan stack
    printf("Stack setelah push: ");
    DisplayStack(s, n);

    // Pop elemen dari stack
    printf("Pop elemen dari stack:\n");
    while (!isEmpty(s)) {
        pop(&s, &temp);
        printf("Elemen yang di-pop: %s\n", temp.itemName);
    }

    // Periksa apakah stack kosong
    printf("Apakah stack kosong setelah pop semua elemen? %s\n", isEmpty(s) ? "Ya" : "Tidak");

    return 0;
}
