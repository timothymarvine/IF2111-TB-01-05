#include <stdio.h>
#include <time.h>
#include "ADT\mesinkata\mesinkata.h"
#include "ADT\mesinkarakter\mesinkarakter.h"
#include "menu.h"

void delay(int seconds){
    clock_t start_time = clock();
    clock_t end_time = start_time + seconds * CLOCKS_PER_SEC;

    while (clock() < end_time);
}


void work(int *uang_asal){
    int pendapatan = 0, durasi = 0;
    char *pekerjaan;
    char tes[50];
    char pilihankerja[20];
    printf("Daftar pekerjaan: \n");
    printf("1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
    printf("Masukkan pekerjaan yang dipilih: ");
    STARTSENTENCE();
    WordToString(currentWord, tes);

    for (int i = 0; i < currentWord.Length; i++) {
        pilihankerja[i] = tes[i];
    }
    pilihankerja[currentWord.Length] = '\0';

    if (manual_strcmp(pilihankerja, "Evil Lab Assistant") == 0){
        pekerjaan = "Evil Lab Assistant";
        pendapatan = 100;
        durasi = 14;
    }else if(manual_strcmp(pilihankerja, "OWCA Hiring Manager") == 0){
        pekerjaan = "OWCA Hiring Manager";
        pendapatan = 4200;
        durasi = 21;
    }else if(manual_strcmp(pilihankerja, "Cikapundunginator") == 0){
        pekerjaan = "Cikapundunginator";
        pendapatan = 7000;
        durasi = 30;
    }else if(manual_strcmp(pilihankerja, "Mewing Specialist") == 0){
        pekerjaan = "Mewing Specialist";
        pendapatan = 10000;
        durasi = 22;
    }else if(manual_strcmp(pilihankerja, "Inator Connoisseur") == 0){
        pekerjaan = "Inator Connoisseur";
        pendapatan = 997;
        durasi = 15;
    }else{
        printf("Pilihan tidak valid!\n");
        return;
    }
    printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", pekerjaan);
    delay(durasi);
    *uang_asal += pendapatan;
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", pendapatan);
    printf("Uang anda sekarang adalah : %d rupiah\n", *uang_asal);
}
