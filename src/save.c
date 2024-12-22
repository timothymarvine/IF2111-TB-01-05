#include <stdio.h>
#include "ADT\mesinkata\mesinkata.h"
#include "ADT\mesinkarakter\mesinkarakter.h"
#include "boolean.h"
#include "save.h"

void SAVE(Word command2, Barang barang[], int jumlahBarang, User user[], int jumlahUser) {
    int i;
    char filename[100] = "src/save/";

    for (i = 0; i < command2.Length; i++) {
        filename[9 + i] = command2.TabWord[i];
    }
    filename[9 + command2.Length] = '\0';

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal menyimpan file.\n");
        return;
    }

    printf("%s\n", filename);
    fprintf(file, "%d\n", jumlahBarang);

    for (i = 0; i < jumlahBarang; i++) {
        fprintf(file, "%d %s\n", barang[i].price, barang[i].name);
    }

    fprintf(file, "%d\n", jumlahUser);

    for (i = 0; i < jumlahUser; i++) {
        fprintf(file, "%d %s %s\n", user[i].uang, user[i].namaUser, user[i].password);
    }

    fclose(file);
    printf("Save file berhasil disimpan.\n");
}
