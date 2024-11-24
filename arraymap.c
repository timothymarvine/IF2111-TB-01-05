#include <stdio.h>
#include <stdlib.h>
#include "arraymap.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk arraymap kosong dengan ukuran InitialSize
 */
arraymap Makearraymap()
{
    arraymap arr;
    arr.A = (TypeMap *) malloc (InitialSize * sizeof(TypeMap));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}
/**
 * Destruktor
 * I.S. arraymap terdefinisi
 * F.S. arraymap->A terdealokasi
 */
void Deallocatearraymap(arraymap *arr)
{
    free(arr->A);
}
/**
 * Fungsi untuk mengetahui apakah suatu arraymap kosong.
 * Prekondisi: arraymap terdefinisi
 */
boolean IsEmptyarrmap(arraymap arr)
{
    return arr.Neff==0;
}
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif arraymap, 0 jika tabel kosong.
 * Prekondisi: arraymap terdefinisi
 */
int Lengtharrmap(arraymap arr)
{
    return arr.Neff;
}
/**
 * Mengembalikan elemen arraymap L yang ke-I (indeks lojik).
 * Prekondisi: arraymap tidak kosong, i di antara 0..Length(arraymap).
 */
TypeMap Getmap(arraymap arr, IdxType i)
{
    return arr.A[i];
}
/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: arraymap terdefinisi
 */
int GetCapacityarrmap(arraymap arr)
{
    return arr.Capacity;
}
/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: arraymap terdefinisi, i di antara 0..Length(arraymap).
 */
void InsertAtarrmap(arraymap *arr, TypeMap el, IdxType i)
{
    if (arr->Neff == arr->Capacity) {
        arr->Capacity *= 2;
        arr->A = (TypeMap *) realloc (arr->A, arr->Capacity * sizeof(TypeMap));
    }
    int j;    
    for (j = Lengtharrmap(*arr); j>i; j--) {
        arr->A[j] = arr->A[j-1];
    } arr->A[i] = el;
    arr->Neff++;
}
/**
 * Fungsi untuk menambahkan elemen baru di akhir arraymap.
 * Prekondisi: arraymap terdefinisi
 */
void InsertLastarrmap(arraymap *arr, TypeMap el)
{
    InsertAtarrmap(arr,el,Lengtharrmap(*arr));
}
/**
 * Fungsi untuk menambahkan elemen baru di awal arraymap.
 * Prekondisi: arraymap terdefinisi
 */
void InsertFirstarrmap(arraymap *arr, TypeMap el)
{
    InsertAtarrmap(arr,el,0);
}
/**
 * Fungsi untuk menghapus elemen di index ke-i arraymap
 * Prekondisi: arraymap terdefinisi, i di antara 0..Length(arraymap).
 */
void DeleteAtarrmap(arraymap *arr, IdxType i)
{
    for (int j=i;j<arr->Neff-1;j++) {
        arr->A[j] = arr->A[j+1];
    } arr->Neff--;
}
/**
 * Fungsi untuk menghapus elemen terakhir arraymap
 * Prekondisi: arraymap tidak kosong
 */
void DeleteLastarrmap(arraymap *arr)
{
    DeleteAtarrmap(arr,Lengtharrmap(*arr)-1);
}
/**
 * Fungsi untuk menghapus elemen pertama arraymap
 * Prekondisi: arraymap tidak kosong
 */
void DeleteFirstarrmap(arraymap *arr)
{
    DeleteAtarrmap(arr,0);
}

/**
 * Fungsi untuk melakukan print suatu arraymap.
 * Prekondisi: array terdefinisi
 */
void Printarraymap(arraymap arr){
    if (IsEmptyarrmap(arr)){
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0;i<arr.Neff-1;i++) {
            CetakMap(arr.A[i]);
        } CetakMap(arr.A[arr.Neff-1]);
        printf("]\n");
    }
}