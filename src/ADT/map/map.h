#ifndef MAP_H
#define MAP_H
#include "..\mesinkata\mesinkata.h"
#include "..\..\boolean.h"
#define Nol 0
#define MaxEl 100
#define Undefined 0

typedef int valuetype;
typedef int address;

typedef struct {
	Produk Key;
	valuetype Value;
} infotype;

typedef struct {
	infotype Elements[MaxEl];
	address Count;
} Map;

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyM(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nol */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyM(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nol */

boolean IsFullM(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, Produk k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, Produk k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, Produk k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberM(Map M, Produk k);
/* Mengembalikan true jika k adalah member dari M */

void ChangeVal(Map *m, Produk i, valuetype v);

void DisplayMap(Map m);

#endif