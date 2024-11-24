#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "..\..\boolean.h"

#define MARK ';'
/* State Mesin */
extern FILE *pita;
extern char currentChar;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita merupakan stdin yang adalah inputan dari pengguna.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void STARTFILE(char *FileName);
/* Mesin siap dioperasikan. Pita merupakan file yang diakses dan disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

// void ADV2();
/* Prosedur ADV yang digunakan pada ADVWORD2 */

char GetCC();
/* Mengirimkan currentChar */

boolean IsEOP();
/* Mengirimkan true jika currentChar = MARK */

#endif