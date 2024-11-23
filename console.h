#ifndef CONSOLE_H
#define CONSOLE_H

#include "implementasiadt.h"
#include "boolean.h"

extern array ListGame;

/* Fitur-fitur pada PURRMART */

void LISTGAME(array StoreList);
/* Menampilkan daftar barang terkini yang dimiliki oleh store */

void DELETEGAME(array *StoreList);
/* Menghapus sebuah barang pada store */

#endif 
