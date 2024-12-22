#include <stdio.h>
#include "linkedlist.h"

void displayMenu() {
    printf("\n=== PROGRAM TEST LINKED LIST ===\n");
    printf("Menu:\n");
    printf("1. Tambahkan elemen ke dalam list\n");
    printf("2. Cetak list (dari depan)\n");
    printf("3. Cetak list (dari belakang)\n");
    printf("4. Hapus elemen pertama\n");
    printf("5. Hapus elemen terakhir\n");
    printf("6. Cari elemen dalam list\n");
    printf("7. Keluar\n");
    printf("Pilihan Anda: ");
}

int main() {
    LinkedList list;        
    Address node;           
    char input[100];        
    int choice;             

    CreateList(&list);

    while (1) {
        displayMenu(); 
        if (scanf("%d", &choice) != 1) { 
            printf("Input tidak valid. Harap masukkan angka.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: 
                printf("Masukkan elemen: ");
                scanf("%s", input);
                node = Allocate(input); 
                if (node != NIL) {
                    InsertLastList(&list, node);
                    printf("Elemen '%s' berhasil ditambahkan.\n", input);
                } else {
                    printf("Gagal mengalokasikan memori untuk elemen '%s'.\n", input);
                }
                break;

            case 2: 
                printf("List dari depan: ");
                if (IsListEmpty(list)) {
                    printf("List kosong.\n");
                } else {
                    PrintListForward(list);
                }
                break;

            case 3: 
                printf("List dari belakang: ");
                if (IsListEmpty(list)) {
                    printf("List kosong.\n");
                } else {
                    PrintListBackward(list);
                }
                break;

            case 4: 
                if (!IsListEmpty(list)) {
                    DeleteFirstList(&list, &node);
                    printf("Elemen '%s' dihapus.\n", InfoL(node));
                    Deallocate(node); 
                } else {
                    printf("List kosong, tidak ada elemen yang dapat dihapus.\n");
                }
                break;

            case 5: 
                if (!IsListEmpty(list)) {
                    DeleteLastList(&list, &node);
                    printf("Elemen '%s' dihapus.\n", InfoL(node));
                    Deallocate(node); 
                } else {
                    printf("List kosong, tidak ada elemen yang dapat dihapus.\n");
                }
                break;

            case 6: 
                printf("Masukkan elemen yang ingin dicari: ");
                scanf("%s", input);
                node = Search(list, input);
                if (node != NIL) {
                    printf("Elemen '%s' ditemukan dalam list.\n", InfoL(node));
                } else {
                    printf("Elemen '%s' tidak ditemukan dalam list.\n", input);
                }
                break;

            case 7: 
                printf("Keluar dari program...\n");
                while (!IsListEmpty(list)) {
                    DeleteFirstList(&list, &node);
                    Deallocate(node);
                }
                printf("Semua elemen dalam list telah dihapus.\n");
                return 0;

            default: 
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    }

    return 0;
} 

