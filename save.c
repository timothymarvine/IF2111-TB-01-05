#include "save.h"
#include <stdio.h>

void SaveData(List_Barang storeList, const char *folderPath, const char *filename) {
    char filePath[100];
    FILE *file;

    snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, filename);

    file = fopen(filePath, "w");
    if (file == NULL) {
        printf("Gagal menyimpan file.\n");
        return;
    }
    for (int i = 0; i < storeList.Neff; i++) {
        fprintf(file, "%s %d\n", storeList.A[i].name, storeList.A[i].price);
    }

    fclose(file);
    printf("Save file berhasil disimpan pada %s.\n", filePath);
}
