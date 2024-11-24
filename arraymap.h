/* Implementasi arraymap menggunakan konsep arraymap dinamis */
/* ElType pada arraymap adalah type bentukan map pada ADT map */
/* ADT digunakan untuk menyimpan scoreboard dari tiap game yang berbentuk arraymap of map */

#ifndef __ARRAYMAP_DINAMIK__
#define __ARRAYMAP_DINAMIK__

#include "../boolean.h"
#include "../map/map.h"

#define InitialSize 10

typedef int IdxType;
typedef Map TypeMap;
typedef struct {
    TypeMap *A;
    int Capacity;
    int Neff;
} arraymap;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk arraymap kosong dengan ukuran InitialSize
 */
arraymap Makearraymap();

/**
 * Destruktor
 * I.S. arraymap terdefinisi
 * F.S. arraymap->A terdealokasi
 */
void Deallocatearraymap(arraymap *arr);

/**
 * Fungsi untuk mengetahui apakah suatu arraymap kosong.
 * Prekondisi: arraymap terdefinisi
 */
boolean IsEmptyarrmap(arraymap arr);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif arraymap, 0 jika tabel kosong.
 * Prekondisi: arraymap terdefinisi
 */
int Lengtharrmap(arraymap arr);

/**
 * Mengembalikan elemen arraymap L yang ke-I (indeks lojik).
 * Prekondisi: arraymap tidak kosong, i di antara 0..Length(arraymap).
 */
TypeMap Getmap(arraymap arr, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: arraymap terdefinisi
 */
int GetCapacityarrmap(arraymap arr);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: arraymap terdefinisi, i di antara 0..Length(arraymap).
 */
void InsertAtarrmap(arraymap *arr, TypeMap el, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir arraymap.
 * Prekondisi: arraymap terdefinisi
 */
void InsertLastarrmap(arraymap *arr, TypeMap el);

/**
 * Fungsi untuk menambahkan elemen baru di awal arraymap.
 * Prekondisi: arraymap terdefinisi
 */
void InsertFirstarrmap(arraymap *arr, TypeMap el);

/**
 * Fungsi untuk menghapus elemen di index ke-i arraymap
 * Prekondisi: arraymap terdefinisi, i di antara 0..Length(arraymap).
 */
void DeleteAtarrmap(arraymap *arr, IdxType i);

/**
 * Fungsi untuk menghapus elemen terakhir arraymap
 * Prekondisi: arraymap tidak kosong
 */
void DeleteLastarrmap(arraymap *arr);

/**
 * Fungsi untuk menghapus elemen pertama arraymap
 * Prekondisi: arraymap tidak kosong
 */
void DeleteFirstarrmap(arraymap *arr);

/**
 * Fungsi untuk melakukan print suatu arraymap.
 * Prekondisi: array terdefinisi
 */
void Printarraymap(arraymap arr);

#endif