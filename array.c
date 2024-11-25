#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk array kosong dengan ukuran InitialSize
 */
array Makearray()
{
    array arr;
    arr.A = (ElType *) malloc (InitialSize * sizeof(ElType));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}

/**
 * Destruktor
 * I.S. array terdefinisi
 * F.S. arr->A terdealokasi
 */
void Deallocatearray(array *arr)
{
    free(arr->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu arr kosong.
 * Prekondisi: arr terdefinisi
 */
boolean IsEmpty(array arr)
{
    return arr.Neff==0;
}

/* Mengecek apakah kata sudah terdapat dalam array */
boolean IsMemberarr(array arr, Word kata){
    boolean found = false;
    int i = 0;
    while (i<arr.Neff && !found){
        if (WordCompare(arr.A[i],kata)){
            found = true;
        } else {i++;}
    } return found;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif arr, 0 jika tabel kosong.
 * Prekondisi: arr terdefinisi
 */
int Length(array arr)
{
    return arr.Neff;
}

/**
 * Mengembalikan elemen arr L yang ke-I (indeks lojik).
 * Prekondisi: arr tidak kosong, i di antara 0..Length(arr).
 */
ElType Get(array arr, IdxType i)
{
    return arr.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: arr terdefinisi
 */
int GetCapacity(array arr)
{
    return arr.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: arr terdefinisi, i di antara 0..Length(arr).
 */
void InsertAt(array *arr, ElType el, IdxType i)
{
    if (arr->Neff == arr->Capacity) {
        arr->Capacity *= 2;
        arr->A = (ElType *) realloc (arr->A, arr->Capacity * sizeof(ElType));
    }
    int j;    
    for (j = Length(*arr); j>i; j--) {
        arr->A[j] = arr->A[j-1];
    } arr->A[i] = el;
    arr->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir arr.
 * Prekondisi: arr terdefinisi
 */
void InsertLast(array *arr, ElType el)
{
    InsertAt(arr,el,Length(*arr));
}

/**
 * Fungsi untuk menambahkan elemen baru di awal arr.
 * Prekondisi: arr terdefinisi
 */
void InsertFirst(array *arr, ElType el)
{
    InsertAt(arr,el,0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i array
 * Prekondisi: arr terdefinisi, i di antara 0..Length(arr).
 */
void DeleteAt(array *arr, IdxType i)
{
    for (int j=i;j<arr->Neff-1;j++) {
        arr->A[j] = arr->A[j+1];
    } arr->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir array
 * Prekondisi: arr tidak kosong
 */
void DeleteLast(array *arr)
{
    DeleteAt(arr,Length(*arr)-1);
}

/**
 * Fungsi untuk menghapus elemen pertama array
 * Prekondisi: arr tidak kosong
 */
void DeleteFirst(array *arr)
{
    DeleteAt(arr,0);
}

/**
 * Fungsi untuk melakukan print suatu array.
 * Prekondisi: arr terdefinisi
 */
void Printarray(array arr)
{
    if (IsEmpty(arr)){
        printf("[]\n");
    } else {
    printf("[");
    for (int i = 0;i<arr.Neff-1;i++) {
        PrintKata(arr.A[i]);printf(",");
    } PrintKata(arr.A[arr.Neff-1]);
    printf("]\n");
    }
}

/**
 * Fungsi untuk melakukan reverse suatu array.
 * Prekondisi: arr terdefinisi
 */
void Reversearray(array *arr)
{
    int i = 0, j = Length(*arr)-1;
    ElType temp;
    while (i<j){
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
        i++; j--;
    }
}

/**
 * Fungsi untuk melakukan copy suatu array.
 * Prekondisi: arr terdefinisi
 */
array Copyarray(array arr)
{
    array arr2;
    arr2 = Makearray();
    for (int i = 0; i<arr.Neff;i++) {
        arr2.A[i] = arr.A[i];
    } arr2.Neff = arr.Neff;
    return arr2;
}