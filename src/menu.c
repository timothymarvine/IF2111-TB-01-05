#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void WelcomeMenu() {
    printf("============ Selamat datang di =============\n");
    printf("================= PURRMART =================\n");
    printf("|         Perintah yang tersedia:          |\n");
    printf("|                 1. START                 |\n");
    printf("|                 2. LOAD                  |\n");
    printf("|                 3. HELP                  |\n");
    printf("|                 4. QUIT                  |\n");
    printf("===========================================\n");
    printf("Masukkan pilihanmu: ");
}

void LoginMenu() {
    printf("\n================ LOGIN MENU ================\n");
    printf("|         Perintah yang tersedia:          |\n");
    printf("|                 1. LOGIN                 |\n");
    printf("|                 2. REGISTER              |\n");
    printf("|                 3. HELP                  |\n");
    printf("|                 4. QUIT                  |\n");
    printf("===========================================\n");
    printf("Masukkan pilihanmu: ");
}

void helpinwelcome() {
    printf("\n=========================== HELP MENU =======================\n");
    printf("|              1. START -> Untuk masuk sesi baru            |\n");
    printf("| 2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi|\n");
    printf("|            3. QUIT -> Untuk keluar dari program           |\n");
    printf("=============================================================\n");
    printf("\n");
}
void helpinlogin(){
    printf("=========================== HELP MENU =======================\n");
    printf("|    1. REGISTER -> Untuk melakukan pendaftaran akun baru   |\n");
    printf("|   2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi  |\n");
    printf("|            3. QUIT -> Untuk keluar dari program           |\n");
    printf("=============================================================\n");
}

void helpinmain(){
    printf("=========================== HELP MENU =======================\n");
    printf("|                  1. WORK -> Untuk bekerja                 |\n");
    printf("|      2. WORK CHALLENGE -> Untuk mengerjakan challenge     |\n");
    printf("|    3. STORE LIST -> Untuk melihat barang-barang di toko   |\n");
    printf("|            3. QUIT -> Untuk keluar dari program           |\n");
    printf("|    4. STORE REQUEST -> Untuk meminta penambahan barang    |\n");
    printf("|5. STORE SUPPLY -> Untuk menambahkan barang dari permintaan|\n");
    printf("|          6. STORE REMOVE -> Untuk menghapus barang        |\n");
    printf("|               7. LOGOUT -> Untuk keluar dari sesi         |\n");
    printf("|       8. SAVE -> Untuk menyimpan state ke dalam file      |\n");
    printf("|            9. QUIT -> Untuk keluar dari program           |\n");
    printf("=============================================================\n");
    printf("\n");
}

// Fungsi untuk menjalankan Main Menu setelah Login
void MainMenu() {
    printf("\n========================= Main Menu ==========================\n");
    printf("|                           1. WORK                           |\n");
    printf("|                      2. WORK CHALLENGE                      |\n");
    printf("|                        3. STORE LIST                        |\n");
    printf("|                       4. STORE REQUEST                      |\n");
    printf("|                       5. STORE SUPPLY                       |\n");
    printf("|                       6. STORE REMOVE                       |\n");
    printf("|                          7. LOGOUT                          |\n");
    printf("|                           8. SAVE                           |\n");
    printf("|                           9. QUIT                           |\n");
    printf("|  10. HELP -> Untuk melihat masing-masing kegunaan command   |\n");
    printf("==============================================================\n");
    printf("Masukkan pilihanmu: ");
}
