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
    printf("           Masukkan pilihanmu: ");
}

void LoginMenu() {
    printf("\n================ LOGIN MENU ================\n");
    printf("|         Perintah yang tersedia:          |\n");
    printf("|                 1. LOGIN                 |\n");
    printf("|                 2. REGISTER              |\n");
    printf("|                 3. HELP                  |\n");
    printf("|                 4. QUIT                  |\n");
    printf("===========================================\n");
    printf("           Masukkan pilihanmu: ");
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
    printf("|              7. PROFILE -> Untuk melihat data diri        |\n");
    printf("|     8. CART ADD <nama> <n> -> Untuk menambahkan barang    |\n");
    printf("|    9. CART REMOVE <nama> <n> -> Untuk mengurangi barang   |\n");
    printf("|  10. CART SHOW -> Untuk menunjukkan barang-barang di cart |\n");
    printf("|         11. CART PAY -> Untuk membeli barang di cart      |\n");
    printf("|     12. HISTORY -> Untuk menunjukkan riwayat pembelian    |\n");
    printf("|  13. WISHLIST ADD -> Untuk menambahkan barang ke wishlist |\n");
    printf("| 14. WISHLIST SWAP <i> <j> -> Untuk menukar oosisi (indeks)|\n");
    printf("| 15. WISHLIST REMOVE <i> -> Untuk menghapus barang (indeks)|\n");
    printf("|    16. WISHLIST REMOVE -> Untuk menghapus barang (nama)   |\n");
    printf("|     17. WISHLIST CLEAR -> Untuk menghapus semua barang    |\n");
    printf("| 18. WISHLIST SHOW -> Untuk menunjukkan barang di wishlist |\n");
    printf("|            19. LOGOUT -> Untuk keluar dari sesi           |\n");
    printf("|       20. SAVE -> Untuk menyimpan state ke dalam file     |\n");
    printf("|            21. QUIT -> Untuk keluar dari program          |\n");
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
    printf("|                          7. PROFILE                         |\n");
    printf("|                    8. CART ADD <nama> <n>                   |\n");
    printf("|                  9. CART REMOVE <nama> <n>                  |\n");
    printf("|                        10. CART SHOW                        |\n");
    printf("|                         11. CART PAY                        |\n");
    printf("|                        12. HISTORY <n>                      |\n");
    printf("|                       13. WISHLIST ADD                      |\n");
    printf("|                   14. WISHLIST SWAP <i> <j>                 |\n");
    printf("|                    15. WISHLIST REMOVE <i>                  |\n");
    printf("|                      16. WISHLIST CLEAR                     |\n");
    printf("|                       17. WISHLIST SHOW                     |\n");
    printf("|                         18. LOGOUT                          |\n");
    printf("|                          19. SAVE                           |\n");
    printf("|                          20. QUIT                           |\n");
    printf("|  21. HELP -> Untuk melihat masing-masing kegunaan command   |\n");
    printf("==============================================================\n");
    printf("                      Masukkan pilihanmu: ");
}