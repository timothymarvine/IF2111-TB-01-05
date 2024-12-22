#include <stdio.h>
#include "map.h"

int main() {
    Map M;
    CreateEmptyMap(&M);
    
    // Menguji fungsi IsEmptyMap
    if (IsEmptyMap(M)) {
        printf("Peta kosong\n");
    } else {
        printf("Peta tidak kosong\n");
    }

    // Menambahkan elemen ke dalam map
    printf("Menambahkan barang A dengan kuantitas 10...\n");
    InsertMap(&M, "A", 10);
    printf("Menambahkan barang B dengan kuantitas 20...\n");
    InsertMap(&M, "B", 20);
    
    // Menguji IsEmptyMap setelah menambah elemen
    if (IsEmptyMap(M)) {
        printf("Peta kosong\n");
    } else {
        printf("Peta tidak kosong\n");
    }
    
    // Menguji IsMemberMap untuk memeriksa keberadaan elemen
    if (IsMemberMap(M, "A")) {
        printf("Barang A ada di dalam peta.\n");
    } else {
        printf("Barang A tidak ada di dalam peta.\n");
    }

    if (IsMemberMap(M, "C")) {
        printf("Barang C ada di dalam peta.\n");
    } else {
        printf("Barang C tidak ada di dalam peta.\n");
    }

    // Menguji idxMap untuk mencari indeks elemen
    int idxA = idxMap(M, "A");
    if (idxA != -1) {
        printf("Indeks barang A adalah: %d\n", idxA);
    } else {
        printf("Barang A tidak ditemukan di peta.\n");
    }

    // Menghapus barang A
    printf("Menghapus barang A...\n");
    DeleteMap(&M, "A");

    // Menguji kembali IsMemberMap dan idxMap setelah penghapusan
    if (IsMemberMap(M, "A")) {
        printf("Barang A ada di dalam peta.\n");
    } else {
        printf("Barang A tidak ada di dalam peta.\n");
    }

    int idxB = idxMap(M, "B");
    if (idxB != -1) {
        printf("Indeks barang B adalah: %d\n", idxB);
    } else {
        printf("Barang B tidak ditemukan di peta.\n");
    }

    // Menghapus barang B
    printf("Menghapus barang B...\n");
    DeleteMap(&M, "B");

    // Memeriksa kembali apakah peta kosong
    if (IsEmptyMap(M)) {
        printf("Peta kosong\n");
    } else {
        printf("Peta tidak kosong\n");
    }

    return 0;
}

