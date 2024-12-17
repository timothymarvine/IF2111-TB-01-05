#ifndef CONSOLE_H
#define CONSOLE_H

#include "ADT\array\array.h"
#include "ADT\array\arraydin.h"
#include "boolean.h"

extern array StoreList;

/* Fitur-fitur pada PURRMART */

void STORELIST(array StoreList);
/* Menampilkan daftar barang terkini yang dimiliki oleh store */

void STOREREMOVE(array *StoreList, ArrayDin *list);
/* Menghapus sebuah barang pada store */

#endif 
