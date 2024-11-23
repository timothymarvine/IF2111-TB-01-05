#ifndef CONSOLE_H
#define CONSOLE_H

#include "implementasiadt.h"
#include "boolean.h"

extern array ListGame;
extern Queue QueueGame;
extern Stack HistoryGame;
extern arraymap ScoreBoardGame;
extern int fitur, mode;

/* Fitur-fitur pada BNMO */

void LISTGAME(array ListGame);
/* Menampilkan daftar game terkini yang dimiliki oleh player */

void DELETEGAME(array *ListGame);
/* Menghapus sebuah game yang dimiliki oleh player */

#endif 