#include <stdio.h>
#include <time.h>

void delay(int seconds){
    clock_t start_time = clock();
    clock_t end_time = start_time + seconds * CLOCKS_PER_SEC;

    while (clock() < end_time);
}

void work(){
    int pilihan, pendapatan = 0, durasi = 0;
    char *pekerjaan;
    printf("Daftar pekerjaan: \n");
    printf("1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");
    printf("Masukkan pekerjaan yang dipilih: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            pekerjaan = "Evil Lab Assistant";
            pendapatan = 100;
            durasi = 14;
            break;
        case 2:
            pekerjaan = "OWCA Hiring Manager";
            pendapatan = 4200;
            durasi = 21;
            break;
        case 3:
            pekerjaan = "Cikapundunginator";
            pendapatan = 7000;
            durasi = 30;
            break;
        case 4:
            pekerjaan = "Mewing Specialist";
            pendapatan = 10000;
            durasi = 22;
            break;
        case 5:
            pekerjaan = "Inator Connoisseur";
            pendapatan = 997;
            durasi = 15;
            break;
        default:
            printf("Pilihan tidak valid!\n");
            return;
        }

        printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", pekerjaan);
        delay(durasi);
        printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", pendapatan);

}

int main(){
    work();
    return 0;
}
    