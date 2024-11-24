/* Implementasi array menggunakan konsep array dinamis */
/* ElType pada array merupakan type bentukan Word pada mesin kata */

#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include "../boolean.h"
#include "../mesinkata/mesin_kata.h"

#define InitialSize 10

typedef int IdxType;
typedef Word ElType;
typedef struct {
    ElType *A;
    int Capacity;
    int Neff;
} array;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk array kosong dengan ukuran InitialSize
 */
array Makearray();

/**
 * Destruktor
 * I.S. array terdefinisi
 * F.S. array->A terdealokasi
 */
void Deallocatearray(array *arr);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(array arr);

/* Mengecek apakah kata sudah terdapat dalam array */
boolean IsMemberarr(array arr, Word kata);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(array arr);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(array arr, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(array arr);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(array *arr, ElType el, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(array *arr, ElType el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(array *arr, ElType el);

/**
 * Fungsi untuk menghapus elemen di index ke-i array
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(array *arr, IdxType i);

/**
 * Fungsi untuk menghapus elemen terakhir array
 * Prekondisi: array tidak kosong
 */
void DeleteLast(array *arr);

/**
 * Fungsi untuk menghapus elemen pertama array
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(array *arr);

/**
 * Fungsi untuk melakukan print suatu array.
 * Prekondisi: array terdefinisi
 */
void Printarray(array arr);

/**
 * Fungsi untuk melakukan reverse suatu array.
 * Prekondisi: array terdefinisi
 */
void Reversearray(array *arr);

/**
 * Fungsi untuk melakukan copy suatu array.
 * Prekondisi: array terdefinisi
 */
array Copyarray(array arr);

#endif