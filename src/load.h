#ifndef LOAD_H
#define LOAD_H

// Struktur data
#include "ADT\array\arraydin.h"

typedef struct {
    char namaUser[50];
    char password[50];
    int uang;
} User;

void LOAD(char command2[], Barang barang[], int *jumlahBarang, User user[], int *jumlahUser);

#endif